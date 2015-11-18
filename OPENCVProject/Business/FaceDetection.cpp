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


#include "opencv2/face.hpp"

#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/flann/miniflann.hpp"
#include "PreTreatment.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace cv;
using namespace std;

//fonctions de reconnaissance disponible :

void recognise(Mat image){

    // Let's say we want to keep 10 Eigenfaces and have a threshold value of 10.0
    int num_components = 10;
    double threshold = 10.0;
    // Then if you want to have a cv::FaceRecognizer with a confidence threshold,
    // create the concrete implementation with the appropiate parameters:
    Mat img1 = treatment(imread("../../OpenCVProject/BDD jpg/img1.jpg"),false);
    Mat img2 = treatment(imread("../../OpenCVProject/BDD jpg/img2.jpg"),false);

    vector<Mat> images = {img1,img2};
    vector<int> labels = {1,2};

    Ptr<face::FaceRecognizer> model = face::createEigenFaceRecognizer(num_components, threshold);
    model->train(images, labels);


    // The following line reads the threshold from the Eigenfaces model:
    //double current_threshold = model->getDouble("threshold");
    // And this line sets the threshold to 0.0:
    //model->set("threshold", 0.0);


    Mat img = imread("../../OpenCVProject/BDD jpg/img0.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    // Get a prediction from the model. Note: We've set a threshold of 0.0 above,
    // since the distance is almost always larger than 0.0, you'll get -1 as
    // label, which indicates, this face is unknown
    int predicted_label = model->predict(img);
    // ...
    cout << predicted_label;

//Ptr<cv::face::FaceRecognizer> createFisherFaceRecognizer(int num_components=0, double threshold=DBL_MAX);

//Ptr<cv::face::FaceRecognizer> createLBPHFaceRecognizer(int radius=1, int neighbors=8, int grid_x=8, int grid_y=8, double threshold=DBL_MAX);

}
