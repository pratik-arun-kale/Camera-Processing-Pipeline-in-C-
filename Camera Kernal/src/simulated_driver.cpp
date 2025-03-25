#include "simulated_driver.hpp"
#include <opencv2/opencv.hpp>

cv::Mat SimulatedCameraDriver::captureImage() {
    return cv::imread("assets/sample.jpg");  // Load test image
}
