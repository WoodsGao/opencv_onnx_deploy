#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include<opencv2/dnn.hpp>
using namespace std;

int main()
{
    cv::Mat src=cv::imread("/home/uisee/Datasets/traffic_bg_cls/tl/tsres854.jpg", 1);
    if(src.empty()) return -1;
    cv::dnn::Net net = cv::dnn::readNetFromONNX("/home/uisee/Projects/pytorch_classification/best.onnx");
    cv::Mat blob = cv::dnn::blobFromImage(src, 1./255., cv::Size(64, 64), cv::Scalar(0,0,0), true);
    net.setInput(blob);
    cv::Mat result = net.forward();
    float tl = exp(result.at<float>(0, 0));
    float bg = exp(result.at<float>(0, 1));

    float confidence = tl / (tl + bg);
    cout<<confidence<<endl;
    return 0;
}
