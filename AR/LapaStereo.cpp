#include "LapaStereo.h"

using namespace cv;
using namespace std;

LapaStereo::LapaStereo():Tc1c2(Eigen::Isometry3d::Identity()){
    Eigen::Matrix4d Tc;

          Tc<<    1.0, 0.0, 0.0, 0.0,
            0.0, 0.8660, 0.5, -0.0285,
            0.0, -0.5, 0.8660, 0.325, //0.325
            0.0, 0.0, 0.0, 1.0;

    Tc1c2 = Eigen::Isometry3d(Tc);
}

void LapaStereo::ImageShow(){
    VideoCapture capture(0);
    if(capture.isOpened())
        cout<<"the camera index is 0!"<<endl;
    else{
        capture.release();
        VideoCapture capture1(2);
        capture = capture1;
        cout<<"the camera index is 2!"<<endl;
        }
    capture.set(CAP_PROP_FRAME_WIDTH,1280);
    capture.set(CAP_PROP_FRAME_HEIGHT,720);

    while(capture.isOpened()){
//        std::unique_lock<std::mutex> lc(mMutex);
        capture >> frame;
        resize(frame,frame,Size(1280,720));

        imshow("LapaStereo_image",frame);
        waitKey(30);
    }
}

cv::Mat LapaStereo::Gettheimage(){
//    std::unique_lock<std::mutex> lc(mMutex);
    return frame;
}
