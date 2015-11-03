//============================================================================
// Name        : Main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : C++ project
//============================================================================


#include <iostream>

#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int argc, const char * argv[]) {
    
    std::cout << "this is opencvproject !\n";
    
    Mat image = imread( "./image2.jpg");
    imshow("image",image);
    waitKey(0);
    return 0;
}