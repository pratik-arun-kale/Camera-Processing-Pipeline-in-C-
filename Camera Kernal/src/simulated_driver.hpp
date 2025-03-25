#ifndef SIMULATED_DRIVER_HPP
#define SIMULATED_DRIVER_HPP

#include <opencv2/opencv.hpp>

class SimulatedCameraDriver {
public:
    cv::Mat captureImage();
};

#endif
