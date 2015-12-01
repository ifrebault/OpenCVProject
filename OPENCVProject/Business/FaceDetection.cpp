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

    int num_components = 10;
    double threshold = 0;
    int radius=1;
    int neighbors=8;
    int grid_x=8;
    int grid_y=8;

    //todo : construction base à refaire une fois BDD dispo
    //Mat img0 = treatment(imread("../../OpenCVProject/BDD jpg/img0.jpg"),false);
    Mat img1 = treatment(imread("../../OpenCVProject/BDD jpg/img1.jpg"),false);
    Mat img2 = treatment(imread("../../OpenCVProject/BDD jpg/img2.jpg"),false);
    Mat img3 = treatment(imread("../../OpenCVProject/BDD jpg/img3.jpg"),false);
    Mat img4 = treatment(imread("../../OpenCVProject/BDD jpg/img4.jpg"),false);
    Mat img5 = treatment(imread("../../OpenCVProject/BDD jpg/img5.jpg"),false);
    Mat img6 = treatment(imread("../../OpenCVProject/BDD jpg/img6.jpg"),false);

    vector<Mat> images = {img1,img2,img3,img4,img5,img6};
    vector<int> labels = {1,2,3,4,5,6};

    //Ptr<face::FaceRecognizer> model = face::createEigenFaceRecognizer(num_components, threshold);
    //Ptr<face::FaceRecognizer> model = face::createFisherFaceRecognizer(num_components, threshold);
    Ptr<cv::face::FaceRecognizer> model = face::createLBPHFaceRecognizer(radius, neighbors, grid_x, grid_y, threshold);

    model->train(images, labels);


    // The following line reads the threshold from the Eigenfaces model:
    //double current_threshold = model->getDouble("threshold");
    // And this line sets the threshold to 0.0:
    //model->set("threshold", 0.0);
    image=treatment(image, false);
    int predicted_label = model->predict(image);
    cout << "label image reconnue :" << endl;
    cout << predicted_label << endl;
    if(predicted_label == -1){
        cout << "face not recognized..." << endl;
    }

}
