#include "detect.hpp"
#include <opencv2/imgproc.hpp>
#include <stdexcept>

/* Constructor -------------------------------------------------- */
HaarDetector::HaarDetector(const std::string& xml, const Params& p)
    : params_(p)  // Match the variable name used in the header
{
    if (!cascade_.load(xml))
        throw std::runtime_error("HaarDetector: cannot load cascade from " + xml);
}

/* -------------------------------------------------------------- */

std::vector<cv::Rect> HaarDetector::operator()(const cv::Mat& frame) const
{
    if (frame.empty())
        return {};                       /* graceful-fail on empty input */

    cv::Mat gray;
    if (frame.channels() == 1)
        gray = frame;
    else
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

    /* Histogram equalisation helps with low-contrast webcams. */
    cv::equalizeHist(gray, gray);

    std::vector<cv::Rect> faces;
    
    // Create a non-const copy of the cascade for detection
    // This is a workaround because detectMultiScale is not marked const in OpenCV
    cv::CascadeClassifier temp_cascade = cascade_;
    temp_cascade.detectMultiScale(gray, faces,
                          params_.scaleFactor,
                          params_.minNeighbours,
                          params_.flags,
                          params_.minSize);
    return faces;
}