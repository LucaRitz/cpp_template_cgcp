#include <template_lib/template_lib.hpp>
#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main(int argc, char* argv[]) {
    auto result = templatelib::type(10);
    std::cout << "Type: " << result._value << std::endl;

    String image_path = R"(resources\color_image.jpg)";
    Mat img = imread(image_path, IMREAD_COLOR);
    if(img.empty())
    {
        std::cout << "Could not read the image: " << image_path << std::endl;
        return 1;
    }
    imshow("Display window", img);
    waitKey(0); // Wait for a keystroke in the window

    return 0;
}