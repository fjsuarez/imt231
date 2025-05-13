#pragma once
/*
 * preprocess.hpp ── cv::Mat ⇆ torch::Tensor helpers
 * -------------------------------------------------
 * The most common call in Lecture 1-2 is `to_tensor()`, which:
 *
 *   • Accepts a BGR (or GRAY) OpenCV image *already* cropped/aligned.
 *   • Converts it to float32, scales to [0, 1], then normalises to [-1, 1].
 *   • Converts BGR → RGB (if 3-channel) and re-orders to N × C × H × W.
 *   • Returns a **contiguous clone** so the caller owns the memory.
 *
 * A reverse `tensor_to_mat()` is provided purely for debug / visualisation.
 */

#include <opencv2/core.hpp>
#include <torch/torch.h>

/** cv::Mat 8-bit (BGR or GRAY) → Torch tensor  (NCHW, float32, [-1,1]).
 *  @param img        Input image (uint8).
 *  @param add_batch  If true (default) prepends dimension 1 for batch.
 *  @return           Float32 tensor; shape = (1,3,H,W) or (1,1,H,W).
 */
torch::Tensor to_tensor(const cv::Mat& img, bool add_batch = true);

/** Reverse helper: tensor (C,H,W) or (1,C,H,W) → BGR 8-bit Mat in [0,255].
 *  Mainly for debugging normalisation pipelines.
 */
cv::Mat tensor_to_mat(torch::Tensor t);
