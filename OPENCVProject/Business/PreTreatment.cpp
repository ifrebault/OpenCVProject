//============================================================================
// Name        : PreTreatment.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : C++ project
//============================================================================

//Entrée : image en couleur
//Sortie : image traitée (en niveau de gris,...)

/*
ETAPES :
- Redimensionner à la même taille
- Passer en niveau de gris
- Egaliser (en option)
*/

#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

Mat treatment(Mat image, bool equal){
    //redimensionnement
    Size size(278,338);
    Mat image2;
    cv::resize(image, image2, size);
    //passage en niveau de gris
    Mat image3 = image2.Mat::clone();
    cv::cvtColor( image2, image3, CV_BGR2GRAY );
    //egalisation
    if (equal){
        cv::equalizeHist(image3, image3);
    }
    return image3;
}