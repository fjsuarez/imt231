#pragma once
/*
 * camera.hpp ── lightweight RAII wrapper for cv::VideoCapture
 * ----------------------------------------------------------
 *  • Opens the requested device (default #0) with optional
 *    width / height / FPS hints.
 *  • Throws std::runtime_error on failure instead of relying
 *    on callers to check .isOpened().
 *  • Move-only: prevents accidental double-close on copy.
 *  • read() returns `false` on end-of-stream; otherwise fills
 *    the supplied cv::Mat with a new frame.
 */

#include <opencv2/videoio.hpp>
#include <opencv2/videoio/registry.hpp>
#include <opencv2/core.hpp>
#include <string>
#include <utility>

class Camera {
public:
    struct Params {
        int   device_id {0};          // /dev/video0 or “0” on Windows
        int   width     {640};        // hint; driver may ignore
        int   height    {480};        // hint; driver may ignore
        int   fps       {30};         // hint; driver may ignore
        int   api       {cv::CAP_ANY};/* pick default backend        */
    };

    explicit Camera(const Params& p);
    Camera() : Camera(Params()) {} 
    /* Move-only --------------------------------------------------- */
    Camera(Camera&&) noexcept;
    Camera& operator=(Camera&&) noexcept;
    Camera(const Camera&)            = delete;
    Camera& operator=(const Camera&) = delete;
    ~Camera();                       // releases device automatically

    /** Grab-and-retrieve one frame. Returns false on EOF/failure. */
    bool read(cv::Mat& out);

    /** Light helper: returns current frame size actually delivered. */
    [[nodiscard]] cv::Size frame_size() const;

    /** For debug logs: e.g. "V4L2: 640×480 @ 30 Hz" */
    [[nodiscard]] std::string backend_string() const;

private:
    cv::VideoCapture cap_;
    Params           params_;
};
