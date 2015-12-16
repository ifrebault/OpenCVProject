#ifndef DEF_FACERECOGNITION
#define DEF_FACERECOGNITION

#include <iostream>
#include <string>
#include <vector>
#include "opencv2/opencv.hpp"

int recognise(cv::Mat image, int avoid);
int findInVector(std::vector<int> vector, int a);
void TestU_recognise (cv::Mat image);

#endif
