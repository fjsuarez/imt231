#include "dataset_csv.hpp"

#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <filesystem>

namespace fs = std::filesystem;

/* ------------------------------------------------------------------ */
std::vector<ImageEntry>
read_csv_list(const std::string& csv_file, char delimiter)
{
    std::ifstream ifs(csv_file);
    if (!ifs)
        throw std::runtime_error("read_csv_list: cannot open " + csv_file);

    std::vector<ImageEntry> list;
    std::string line;

    const fs::path root = fs::absolute(fs::path(csv_file)).parent_path();

    while (std::getline(ifs, line)) {
        /* trim whitespace */
        line.erase(0,  line.find_first_not_of(" \t\r\n"));
        line.erase(line.find_last_not_of(" \t\r\n") + 1);

        if (line.empty() || line.front() == '#') continue;   /* skip comments */

        std::stringstream ss(line);
        std::string path, label_str;

        if (!std::getline(ss, path,     delimiter) ||
            !std::getline(ss, label_str))
            throw std::runtime_error("read_csv_list: malformed line → " + line);

        /* trim again after splitting */
        path.erase(0,  path.find_first_not_of(" \t"));
        path.erase(path.find_last_not_of(" \t") + 1);
        label_str.erase(0,  label_str.find_first_not_of(" \t"));
        label_str.erase(label_str.find_last_not_of(" \t") + 1);

        int label = std::stoi(label_str);
        fs::path full_path = fs::path(path).is_relative() ? root / path : fs::path(path);

        list.push_back({ full_path.string(), label });
    }
    return list;
}

/* ------------------------------------------------------------------ */
CSVDataset::CSVDataset(const std::string& csv_file,
                       char               delimiter,
                       int                edge_len,
                       bool               convert_gray)
    : entries_{ read_csv_list(csv_file, delimiter) },
      edge_len_{ edge_len },
      gray_{ convert_gray }
{
    if (entries_.empty())
        throw std::runtime_error("CSVDataset: empty CSV — no samples found");
}

/* ------------------------------------------------------------------ */
/* helper: OpenCV Mat → Torch Tensor (float32, NCHW, range [-1,1]) */
static torch::Tensor mat_to_tensor(const cv::Mat& img_bgr_or_gray,
                                   bool          gray)
{
    cv::Mat img;

    if (gray) {
        img = img_bgr_or_gray.clone();                         /* keep 1-ch */
    } else {
        cv::cvtColor(img_bgr_or_gray, img, cv::COLOR_BGR2RGB); /* BGR→RGB */
    }
    img.convertTo(img, CV_32F, 1.0 / 255.0);                   /* 0–1 float */

    auto options = torch::TensorOptions().dtype(torch::kFloat32).device(torch::kCPU);

    torch::Tensor t;
    if (gray) {
        t = torch::from_blob(img.data, {1, img.rows, img.cols}, options).clone();
    } else {
        t = torch::from_blob(img.data, {img.rows, img.cols, 3}, options)
               .permute({2, 0, 1})   /* HWC → CHW */
               .clone();
    }
    /* Normalise to [-1,1]  (optional but common) */
    t = (t - 0.5f) / 0.5f;
    return t;
}

/* ------------------------------------------------------------------ */
torch::data::Example<> CSVDataset::get(size_t index)
{
    const auto& e = entries_.at(index);

    int imread_flag = gray_ ? cv::IMREAD_GRAYSCALE : cv::IMREAD_COLOR;
    cv::Mat img = cv::imread(e.path, imread_flag);
    if (img.empty())
        throw std::runtime_error("CSVDataset: cannot read image " + e.path);

    cv::resize(img, img, {edge_len_, edge_len_},
               0, 0,
               (img.cols > edge_len_ ? cv::INTER_AREA : cv::INTER_LINEAR));

    torch::Tensor data   = mat_to_tensor(img, gray_);
    torch::Tensor target = torch::tensor(e.label, torch::kInt64);

    return { std::move(data), std::move(target) };
}
