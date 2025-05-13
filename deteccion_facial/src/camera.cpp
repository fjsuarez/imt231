#include "camera.hpp"
#include <opencv2/imgcodecs.hpp>   // only for fourcc → string utility
#include <stdexcept>
#include <sstream>
#include <utility>

/* helper: set property only if user requested a positive value */
static void trySet(cv::VideoCapture& c, int prop, double val)
{
    if (val > 0) c.set(prop, val);
}

/* -------------------------------------------------------------- */
Camera::Camera(const Params& p) : params_(p)
{
    if (!cap_.open(p.device_id, p.api))
        throw std::runtime_error("Camera: cannot open device #" +
                                 std::to_string(p.device_id));

    /* Hint desired capture format (may silently fail). */
    trySet(cap_, cv::CAP_PROP_FRAME_WIDTH , p.width);
    trySet(cap_, cv::CAP_PROP_FRAME_HEIGHT, p.height);
    trySet(cap_, cv::CAP_PROP_FPS         , p.fps);
}

/* move-ctor ----------------------------------------------------- */
Camera::Camera(Camera&& other) noexcept
    : cap_{std::move(other.cap_)},
      params_{other.params_}
{
    other.params_.device_id = -1;   // mark as “moved-from”
}

/* move-assign --------------------------------------------------- */
Camera& Camera::operator=(Camera&& other) noexcept
{
    if (this != &other) {
        cap_          = std::move(other.cap_);
        params_       = other.params_;
        other.params_.device_id = -1;
    }
    return *this;
}

/* dtor ---------------------------------------------------------- */
Camera::~Camera()
{
    if (cap_.isOpened())
        cap_.release();
}

/* read ---------------------------------------------------------- */
bool Camera::read(cv::Mat& out)
{
    return cap_.read(out);
}

/* frame_size ---------------------------------------------------- */
cv::Size Camera::frame_size() const
{
    return { static_cast<int>(cap_.get(cv::CAP_PROP_FRAME_WIDTH)),
             static_cast<int>(cap_.get(cv::CAP_PROP_FRAME_HEIGHT)) };
}

/* backend_string ------------------------------------------------ */
std::string Camera::backend_string() const
{
    std::ostringstream oss;
    cv::VideoCaptureAPIs api = static_cast<cv::VideoCaptureAPIs>(cap_.get(cv::CAP_PROP_BACKEND));
    oss << cv::videoio_registry::getBackendName(api)
        << ": " << frame_size().width << "×" << frame_size().height
        << " @ " << static_cast<int>(cap_.get(cv::CAP_PROP_FPS)) << " Hz";
    return oss.str();
}
