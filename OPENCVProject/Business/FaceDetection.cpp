//============================================================================
// Name        : FaceDetection.cpp
// Author      :
// Version     :
// Copyright   : http://docs.opencv.org/2.4/doc/tutorials/objdetect/cascade_classifier/cascade_classifier.html
// Description : C++ project
//============================================================================

//Entrée : Image
//Sortie : Matrice

/*
ETAPES :
- Training avec la base dispo (à faire ultérieurement)
- Récupération du visage seul 
- Application de l'algo (EigenFaces ?)
- ssortie du résultat
*/

#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "PreTreatment.h"
#include "FaceDetection.h"
#include "FaceExtraction.h"

#include "opencv2/face.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace cv;
using namespace std;

void recognise(Mat image){

    int num_components = 10;
    double threshold = 10;
    int radius=1;
    int neighbors=8;
    int grid_x=8;
    int grid_y=8;

    //todo : construction base à refaire une fois BDD dispo
    Mat img0 = imread("../../OpenCVProject/BDD jpg/img0.jpg");
    Mat img1 = imread("../../OpenCVProject/BDD jpg/img1.jpg");
    Mat img2 = imread("../../OpenCVProject/BDD jpg/img2.jpg");
    Mat img3 = imread("../../OpenCVProject/BDD jpg/img3.jpg");
    Mat img4 = imread("../../OpenCVProject/BDD jpg/img4.jpg");
    Mat img5 = imread("../../OpenCVProject/BDD jpg/img5.jpg");
    Mat img6 = imread("../../OpenCVProject/BDD jpg/img6.jpg");
    Mat img7 = imread("../../OpenCVProject/BDD jpg/img7.jpg");
    Mat img8 = imread("../../OpenCVProject/BDD jpg/img8.jpg");
    Mat img9 = imread("../../OpenCVProject/BDD jpg/img9.jpg");
    Mat img10 = imread("../../OpenCVProject/BDD jpg/img10.jpg");
    Mat img11 = imread("../../OpenCVProject/BDD jpg/img11.jpg");
    Mat img12 = imread("../../OpenCVProject/BDD jpg/img12.jpg");
    Mat img13 = imread("../../OpenCVProject/BDD jpg/img13.jpg");
    Mat img14 = imread("../../OpenCVProject/BDD jpg/img14.jpg");
    
    

    img0=treatment(detectFace(img0),false);
    img1=treatment(detectFace(img1),false);
    img2=treatment(detectFace(img2),false);
    img3=treatment(detectFace(img3),false);
    img4=treatment(detectFace(img4),false);
    img5=treatment(detectFace(img5),false);
    img6=treatment(detectFace(img6),false);
    img7=treatment(detectFace(img7),false);
    img8=treatment(detectFace(img8),false);
    img9=treatment(detectFace(img9),false);
    img10=treatment(detectFace(img10),false);
    img11=treatment(detectFace(img11),false);
    img13=treatment(detectFace(img13),false);
    img14=treatment(detectFace(img14),false);
    
    
    vector<Mat> images = {img0,img1,img2,img3,img4,img5,img6,img7,img8,img9,img10,img11,img13,img14};
    vector<int> labels = {0,1,2,3,4,5,6,7,8,9,10,11,13,14};
    
    Ptr<face::FaceRecognizer> model = face::createEigenFaceRecognizer(num_components, threshold);
    //Ptr<face::FaceRecognizer> model = face::createFisherFaceRecognizer(num_components, threshold);
    //Ptr<cv::face::FaceRecognizer> model = face::createLBPHFaceRecognizer(radius, neighbors, grid_x, grid_y, threshold);
    
    model->train(images, labels);

    // The following line reads the threshold from the Eigenfaces model:
    //double current_threshold = model->getDouble("threshold");
    // And this line sets the threshold to 0.0:
    //model->set("threshold", 0.0);
    
    image=treatment(detectFace(image),false);

    imshow("face only",image);
    waitKey(0);
    
    int predicted_label = model->predict(image);
    cout << "label image reconnue :" << endl;
    cout << predicted_label << endl;
    if(predicted_label == -1){
        cout << "face not recognized..." << endl;
    }
}

