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
#include "../Business/FaceDetection.h"

#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main(int argc, const char * argv[]) {
    
    std::cout << "this is opencvproject !\n";
    //lecture dans la base de données
    Mat image = imread("../../OpenCVProject/BDD jpg/img8.jpg");
    std::cout << image.size() << endl;
    imshow("image",treatment(image,false));
    waitKey(0);
    //envoie vers les fonctions de la couche Business
    treatment(image,false);
    //vérification du bon fonctionnement de la classe patient
    Patient patient0;
    patient0.getName();
    std::cout << patient0.getName() <<" is my name"<< endl;
    
    recognise(image);
    
    return 0;
    
}
