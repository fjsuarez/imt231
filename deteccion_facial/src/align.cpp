#include "align.hpp"
#include <opencv2/imgproc.hpp>
#include <stdexcept>
#include <cmath>

namespace {

/* makeSquare ── expand a rectangle to the smallest enclosing square,
 *               centred on the original rect.  Clip later.         */
static cv::Rect makeSquare(const cv::Rect& r, const cv::Size& bounds)
{
    int sz   = std::max(r.width, r.height);
    int cx   = r.x + r.width  / 2;
    int cy   = r.y + r.height / 2;

    int x0   = cx - sz / 2;
    int y0   = cy - sz / 2;

    // Create explicit Rect objects instead of using braced initializers with &
    cv::Rect square(x0, y0, sz, sz);
    cv::Rect bounds_rect(0, 0, bounds.width, bounds.height);
    return square & bounds_rect;
}

} // anonymous namespace



/* -------------------------------------------------------------- *
 *  Simple centre-crop & resize                                   *
 * -------------------------------------------------------------- */
cv::Mat align_and_crop(const cv::Mat& img,
                       const cv::Rect& face,
                       int edge_len,
                       bool keep_square)
{
    if (img.empty()) throw std::invalid_argument("align_and_crop: empty image");

    cv::Rect roi = keep_square ? makeSquare(face, img.size())
                               : (face & cv::Rect{0, 0, img.cols, img.rows});

    if (roi.width <= 0 || roi.height <= 0)
        throw std::runtime_error("align_and_crop: invalid ROI after clipping");

    cv::Mat patch = img(roi).clone();                       // deep copy
    cv::resize(patch, patch, {edge_len, edge_len},
               0, 0, (edge_len < roi.width) ?
                     cv::INTER_AREA : cv::INTER_LINEAR);

    return patch;                                           // BGR, 8-bit
}



/* -------------------------------------------------------------- *
 *  Landmark-driven: rotate so eyes are horizontal                *
 * -------------------------------------------------------------- */
cv::Mat align_and_crop(const cv::Mat& img,
                       const cv::Point2f& le,
                       const cv::Point2f& re,
                       int edge_len)
{
    if (img.empty()) throw std::invalid_argument("align_and_crop: empty image");

    // 1.  Compute angle & scale so that inter-eye distance == 0.35 * edge_len
    const double dx = re.x - le.x;
    const double dy = re.y - le.y;
    const double dist = std::hypot(dx, dy);
    const double desired = 0.35 * edge_len;
    const double scale   = desired / dist;
    const double angle   = std::atan2(dy, dx) * 180.0 / CV_PI;

    // 2.  Build rotation matrix around left eye
    cv::Mat M = cv::getRotationMatrix2D(le, angle, scale);

    // 3.  Move eyes so that left eye lands at (0.3*edge_len, 0.35*edge_len)
    const double tx = edge_len * 0.3  - le.x;
    const double ty = edge_len * 0.35 - le.y;
    M.at<double>(0,2) += tx;
    M.at<double>(1,2) += ty;

    // 4.  Warp + crop
    cv::Mat aligned;
    cv::warpAffine(img, aligned, M, {edge_len, edge_len},
                   cv::INTER_LINEAR, cv::BORDER_REFLECT_101);

    return aligned;                                         // BGR, 8-bit
}
