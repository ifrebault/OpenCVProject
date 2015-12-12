 //============================================================================
// Name        : PreTreatment.cpp
// Author      : IFREBAULT
// Version     :
// Copyright   : 
// Description : C++ project
//============================================================================

//Entrée : image en couleur
//Sortie : image traitée (en niveau de gris, resizé et équalisée si nécessaire)

/*
ETAPES :
- Redimensionner à la même taille
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
    //egalisation
    if (equal){
        cv::equalizeHist(image2, image2);
    }
    return image2;
}