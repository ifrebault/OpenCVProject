#ifndef DEF_FACERECOGNITION
#define DEF_FACERECOGNITION

#include <iostream>
#include <string>
#include <vector>
#include "opencv2/opencv.hpp"

void recognise(cv::Mat image);
int findInVector(std::vector<int> vector, int a);

#endif
