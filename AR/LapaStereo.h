#ifndef LAPASTEREO_H
#define LAPASTEREO_H


#include <iostream>
#include <Eigen/Dense>
#include <Eigen/Core>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <mutex>

class LapaStereo
{
public:
    LapaStereo();
    void ImageShow();
    cv::Mat Gettheimage();
    Eigen::Isometry3d Tc1c2;

private:
    cv::Mat frame;
    std::mutex mMutex;
};












#endif // LAPASTEREO_H
