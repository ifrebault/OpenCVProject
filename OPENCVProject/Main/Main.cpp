//============================================================================
// Name        : Main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : C++ project
//============================================================================


#include <iostream>
#include <ctime>

#include "../Business/Patient.h"
//#include "../Business/Picture.h"
//#include "../Business/Disease.h"

#include "../Business/PreTreatment.h"
#include "../Business/FaceRecognition.h"

#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int argc, const char * argv[]) {
    
    std::cout << "this is opencvproject !\n";
    
    //lecture du fichier à analyser
    //Mat image = imread('"imgTemp.jpg");
    //Mat image = imread("../../OpenCVProject/BDDjpg/img4.jpg");
    Mat image = imread("../../OpenCVProject/BDDjpg/img19.jpg");
    cout << image.size() << endl;
    imshow("image",treatment(image,false));
    waitKey(0);
    //envoi vers les fonctions de la couche Business
    recognise(image);
    
    return 0;
    
}
