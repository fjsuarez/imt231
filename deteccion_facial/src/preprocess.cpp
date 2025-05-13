#include "preprocess.hpp"
#include <opencv2/imgproc.hpp>
#include <stdexcept>

namespace {

/* -------------------------------------------------------------- *
 *  Internal: cv::Mat (BGR/GRAY) → float32 Torch tensor (C,H,W)   *
 * -------------------------------------------------------------- */
static torch::Tensor mat_to_chw(const cv::Mat& img)
{
    if (img.empty())
        throw std::invalid_argument("to_tensor: empty cv::Mat");

    cv::Mat tmp;

    if (img.channels() == 3) {
        cv::cvtColor(img, tmp, cv::COLOR_BGR2RGB);
    } else if (img.channels() == 1) {
        tmp = img;                                   // keep GRAY as-is
    } else {
        throw std::invalid_argument("to_tensor: unsupported #channels");
    }

    tmp.convertTo(tmp, CV_32F, 1.0 / 255.0);         /* scale → [0,1]  */

    auto opts = torch::TensorOptions()
                    .dtype(torch::kFloat32)
                    .device(torch::kCPU);

    torch::Tensor t;
    if (tmp.channels() == 3) {
        /* HWC → CHW */
        t = torch::from_blob(tmp.data, {tmp.rows, tmp.cols, 3}, opts)
                .permute({2, 0, 1})                  /* C,H,W order    */
                .clone();
    } else { /* 1-channel */
        t = torch::from_blob(tmp.data, {1, tmp.rows, tmp.cols}, opts)
                .clone();
    }

    /* Normalise to [-1,1] (FaceNet / ArcFace convention) */
    t = (t - 0.5f) / 0.5f;

    return t.contiguous();
}

} // anonymous namespace



/* ------------------------------------------------------------------ */
torch::Tensor to_tensor(const cv::Mat& img, bool add_batch)
{
    torch::Tensor t = mat_to_chw(img);
    if (add_batch)
        t = t.unsqueeze(0);            /* (C,H,W) → (1,C,H,W) */
    return t;
}



/* ------------------------------------------------------------------ */
cv::Mat tensor_to_mat(torch::Tensor t)
{
    if (t.dim() == 4)                  /* (1,C,H,W) → (C,H,W) */
        t = t.squeeze(0);

    if (t.ndimension() != 3)
        throw std::invalid_argument("tensor_to_mat: expect 3D tensor");

    /* Undo normalisation */
    t = t.mul(0.5f).add(0.5f).clamp(0.0f, 1.0f);      /* back to [0,1] */

    t = t.mul(255).to(torch::kU8).contiguous();

    int C = t.size(0), H = t.size(1), W = t.size(2);

    if (C == 3) {
        auto tmp = torch::permute(t, {1, 2, 0}).clone();  /* CHW→HWC */
        cv::Mat rgb(H, W, CV_8UC3, tmp.data_ptr());
        cv::Mat bgr;
        cv::cvtColor(rgb, bgr, cv::COLOR_RGB2BGR);
        return bgr.clone();
    } else if (C == 1) {
        cv::Mat gray(H, W, CV_8UC1, t.data_ptr());
        return gray.clone();
    } else {
        throw std::invalid_argument("tensor_to_mat: unsupported #channels");
    }
}
