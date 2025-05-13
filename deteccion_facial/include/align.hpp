#pragma once
/*
 * align.hpp ── trivial “alignment” helper
 * ---------------------------------------------------------
 * Given a BGR frame and a face bounding‐box (usually from a Haar   *
 * or HOG detector), the routine:                                   *
 *   1) optionally expands the box to a square (so the face isn’t   *
 *      distorted when resized);                                    *
 *   2) clips the box to the image bounds (guards against           *
 *      partial detections on edges);                               *
 *   3) crops, resizes to a fixed edge length (default 112×112);    *
 *   4) returns the result **still in BGR** so the caller can       *
 *      decide when to colour-convert or normalise.                 *
 *
 * NOTE  This is a deliberately *minimal* baseline.  For a proper   *
 *       alignment by eye landmarks, add a facemark detector and    *
 *       call the overload further below.                           */
#include <opencv2/core.hpp>

/**
 * @param img         Input frame in BGR colour space.
 * @param face        Bounding rectangle in the same coordinates.
 * @param edge_len    Width == height of the output patch in pixels.
 * @param keep_square If true, expands the rect equally to a square
 *                    before cropping (recommended).
 * @return            Cropped & resized patch; deep-copied (own data).
 */
cv::Mat align_and_crop(const cv::Mat& img,
                       const cv::Rect& face,
                       int edge_len = 112,
                       bool keep_square = true);


/* ---------- OPTIONAL: landmark-driven version ------------------ */
/*
 * If you later add an eye-landmark detector (e.g. Facemark LBF),
 * you can call this overload to rotate & scale so that the line
 * connecting the eyes is horizontal and the inter-eye distance
 * is constant.
 *
 * @param left_eye, right_eye ── pixel coords (relative to `img`).
 */
cv::Mat align_and_crop(const cv::Mat& img,
                       const cv::Point2f& left_eye,
                       const cv::Point2f& right_eye,
                       int edge_len = 112);
