//============================================================================
// Name        : Main.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : C++ project
//============================================================================

//#define TESTU

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
    
    
    
#ifdef TESTU // activation du test unitaire
    
    std::cout << "this is opencvproject !\n";
    
    
    //lecture du fichier à analyser
    //Mat image = imread("imgTemp.jpg");
    Mat imageTest = imread("../../OpenCVProject/BDDjpg/img15.jpg");

    TestU_recognise(imageTest);
    TestU_treatment(imageTest, false);
    
    return 0;
    
    #else
    
    Mat image = imread("../../OpenCVProject/BDDjpg/img15.jpg");
    imshow("image",treatment(image,false));
    waitKey(0);
    //envoi vers les fonctions de la couche Business
    recognise(image);
    
    
    #endif
    
    
    
}