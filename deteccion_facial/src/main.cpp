#include "detect.hpp"
#include "align.hpp"      // returns cropped cv::Mat
#include "preprocess.hpp" // cv::Mat → torch::Tensor
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp> // For rectangle, drawing functions
#include <opencv2/videoio.hpp>  // For VideoCapture
#include <torch/torch.h>
#include <iostream>
#include <string>
#include <filesystem>
// #include "camera.hpp"

int main(int argc, char* argv[]) {
    // Default video path
    std::string videoPath = "/home/fjsuarez/deteccion_facial/data/samples/test.mp4";
    
    // Check if a video path was provided as a command-line argument
    if (argc > 1) {
        videoPath = argv[1];
        std::cout << "Using video from command line: " << videoPath << std::endl;
    } else {
        std::cout << "No video path provided, using default: " << videoPath << std::endl;
        std::cout << "Usage: " << (argc > 0 ? argv[0] : "./hello_image") << " [path_to_video]" << std::endl;
    }

    // Check if the file exists
    if (!std::filesystem::exists(videoPath)) {
        std::cerr << "Error: Video file does not exist: " << videoPath << std::endl;
        return -1;
    }
    
    // Open the video file
    cv::VideoCapture cap(videoPath);
    
    // Check if video file was opened successfully
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open video file: " << videoPath << std::endl;
        return -1;
    }
    
    std::cout << "Video opened successfully: " << videoPath << std::endl;
    std::cout << "Frame size: " << cap.get(cv::CAP_PROP_FRAME_WIDTH) << "x" 
    << cap.get(cv::CAP_PROP_FRAME_HEIGHT) << std::endl;
    
    // If we want to use webcam
    // Camera cam;
    // Initialize face detector
    HaarDetector detect{"/usr/share/opencv4/haarcascades/haarcascade_frontalface_default.xml"};

    cv::Mat frame;
    while (cap.read(frame)) {
        // Process each detected face in the frame
        for (auto r : detect(frame)) {
            cv::rectangle(frame, r, {0, 255, 0}, 2);
            auto face = align_and_crop(frame, r);
            auto t = to_tensor(face);  // (1,3,112,112) float32
            std::cout << "L2-norm: " << t.norm().item<float>() << '\n';
        }
        
        // Show the processed frame
        cv::imshow("video", frame);
        
        // Break loop if ESC is pressed
        if (cv::waitKey(30) == 27) break;
    }
    
    // Release resources
    cap.release();
    cv::destroyAllWindows();
    
    return 0;
}