#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>

int main() {
    // 打开视频文件
    cv::VideoCapture cap("./temp/shelf.mp4");
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open video." << std::endl;
        return -1;
    }

    cv::Mat frame;
    int frameCount = 0;
    while (true) {
        cap >> frame; // 读取新的一帧
        if (frame.empty()) {
            break; // 如果读取帧为空，则结束循环
        }
        std::cout<<frameCount<<std::endl;
        std::string filename = "./temp/imgs/frame_" + std::to_string(frameCount++) + ".png";
        cv::imwrite(filename, frame); // 保存帧为图片
        if (frameCount > 100){
            break;
        }
    }

    cap.release(); // 释放视频文件
    return 0;
}