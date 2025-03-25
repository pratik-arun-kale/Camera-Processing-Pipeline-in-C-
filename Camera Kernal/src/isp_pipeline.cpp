#include "isp_pipeline.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>

void process_image(cv::Mat& image) {
    if (image.empty()) return;

    // 1. Histogram Equalization (improve contrast)
    if (image.channels() == 3) {
        cv::Mat ycrcb;
        cv::cvtColor(image, ycrcb, cv::COLOR_BGR2YCrCb);
        std::vector<cv::Mat> channels;
        cv::split(ycrcb, channels);
        cv::equalizeHist(channels[0], channels[0]);
        cv::merge(channels, ycrcb);
        cv::cvtColor(ycrcb, image, cv::COLOR_YCrCb2BGR);
    } else {
        cv::equalizeHist(image, image);
    }

    // 2. Convert to grayscale for Canny
    cv::Mat gray;
    cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);

    // 3. Apply Gaussian blur to smooth
    cv::Mat blurred;
    cv::GaussianBlur(gray, blurred, cv::Size(5, 5), 1.5);

    // 4. Edge detection using Canny
    cv::Mat edges;
    cv::Canny(blurred, edges, 50, 150);

    // 5. Show edges side-by-side
    cv::imshow("Canny Edges", edges);
}
