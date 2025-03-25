#include "simulated_driver.hpp"
#include "isp_pipeline.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

int main(int argc, char* argv[]) {
    bool useWebcam = false;

    // Check if user passed --use-webcam
    for (int i = 1; i < argc; i++) {
        if (std::string(argv[i]) == "--use-webcam") {
            useWebcam = true;
        }
    }

    if (useWebcam) {
        std::cout << "Using webcam as input..." << std::endl;
        cv::VideoCapture cap(0);  // Open default webcam (ID=0)

        if (!cap.isOpened()) {
            std::cerr << "Error: Unable to open webcam!" << std::endl;
            return -1;
        }

        cv::Mat frame;
        while (true) {
            cap >> frame;  // Capture frame

            if (frame.empty()) break;

            // ✅ Process frame (non-const reference)
            process_image(frame);

            // Display result
            cv::imshow("Processed Frame", frame);

            if (cv::waitKey(1) == 27) break;  // Press 'Esc' to exit
        }

        cap.release();
        cv::destroyAllWindows();
    } else {
        std::cout << "Using Simulated Camera Driver..." << std::endl;
        SimulatedCameraDriver driver;
        cv::Mat image = driver.captureImage();

        // ✅ Process image (non-const reference)
        process_image(image);

        cv::imshow("Processed Image", image);
        cv::waitKey(0);
    }

    return 0;
}
