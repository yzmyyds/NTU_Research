#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
    // 创建一个 256x256 的灰度图，全部像素初始化为 128
    Mat img(256, 256, CV_8UC1, Scalar(128));
    if (img.empty()) {
        cout << "Failed to create image" << endl;
        return -1;
    }

    // 在窗口中显示图像
    imshow("Test Image", img);
    cout << "Press any key in the window to exit..." << endl;
    waitKey(0); // 等待按键
    return 0;
}