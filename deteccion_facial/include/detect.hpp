#pragma once
#include <opencv2/objdetect.hpp>
#include <opencv2/core.hpp>
#include <string>
#include <vector>

/** 
 * Simple OpenCV face detector based on Haar features.
 * Just a convenience wrapper around CascadeClassifier with useful defaults.
 */
class HaarDetector {
public:
    /** Tweak if faces are missed or you get false positives. */
    struct Params {
        double scaleFactor   {1.1};       // pyramid scaling step
        int    minNeighbours {5};         // min matches needed
        int    flags         {0};         // old CV_HAAR_XXX flags 
        cv::Size minSize     {30, 30};    // smallest box to detect
    };

    /**
     * Loads pre-trained XML cascade file, e.g. "haarcascade_frontalface_alt.xml".
     * You can download these from https://github.com/opencv/opencv/tree/master/data/haarcascades.
     *
     * @param xml       Path to OpenCV CascadeClassifier xml file.
     * @param p         Optional detection parameters.
     */
    explicit HaarDetector(const std::string& xml, const Params& p);
    
    // Add a default constructor that delegates
    explicit HaarDetector(const std::string& xml) : HaarDetector(xml, Params()) {}

    /** Run face detection on a frame. Returns face bounding-boxes, if any. */
    std::vector<cv::Rect> operator()(const cv::Mat& frame) const;

private:
    Params                params_;  // Changed from p_ to params_ to match usage
    cv::CascadeClassifier cascade_;
};