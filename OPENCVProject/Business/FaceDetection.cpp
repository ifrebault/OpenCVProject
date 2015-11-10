//============================================================================
// Name        : FaceDetection.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : C++ project
//============================================================================

//Entrée : Image
//Sortie : Matrice

/*
ETAPES :
- Training avec la base dispo (à faire ultérieurement)
- application de l'algo (EigenFaces ?)
- sortie du résultat
*/

//#include "opencv2/contrib/contrib.hpp"
#include "FaceRecognizer.h"

#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace cv;
using namespace std;

//fonctions de reconnaissance disponible :

Ptr<FaceRecognizer> createEigenFaceRecognizer(int num_components=0, double threshold=DBL_MAX);

Ptr<FaceRecognizer> createFisherFaceRecognizer(int num_components=0, double threshold=DBL_MAX);

Ptr<FaceRecognizer> createLBPHFaceRecognizer(int radius=1, int neighbors=8, int grid_x=8, int grid_y=8, double threshold=DBL_MAX);


