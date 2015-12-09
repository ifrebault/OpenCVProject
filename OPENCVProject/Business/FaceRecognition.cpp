//============================================================================
// Name        : FaceRecognition.cpp
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
#include "FaceRecognition.h"
#include "FaceExtraction.h"

#include "opencv2/face.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace cv;
using namespace std;

void recognise(Mat image){

    int num_components = 0;
    double threshold = 0;
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
    Mat img15 = imread("../../OpenCVProject/BDD jpg/img15.jpg");
    Mat img16 = imread("../../OpenCVProject/BDD jpg/img16.jpg");
    Mat img17 = imread("../../OpenCVProject/BDD jpg/img17.jpg");
    Mat img18 = imread("../../OpenCVProject/BDD jpg/img17.jpg");

    img0=treatment(detectFace(img0),true);
    img1=treatment(detectFace(img1),true);
    img2=treatment(detectFace(img2),true);
    img3=treatment(detectFace(img3),true);
    img4=treatment(detectFace(img4),true);
    img5=treatment(detectFace(img5),true);
    img6=treatment(detectFace(img6),true);
    img7=treatment(detectFace(img7),true);
    img8=treatment(detectFace(img8),true);
    img9=treatment(detectFace(img9),true);
    img10=treatment(detectFace(img10),true);
    img11=treatment(detectFace(img11),true);
    img12=treatment(detectFace(img12),true);
    img13=treatment(detectFace(img13),true);
    img14=treatment(detectFace(img14),true);
    img15=treatment(detectFace(img15),true);
    img16=treatment(detectFace(img16),true);
    img17=treatment(detectFace(img17),true);
    img18=treatment(detectFace(img18),true);
    
    vector<Mat> images = {img0,img1,img2,img3,img4,img5,img6,img7,img8,img9,img10,img11,img12,img13,img14,img15,img16,img17,img18};
    vector<int> labels = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
    
    //Ptr<face::FaceRecognizer> model = face::createEigenFaceRecognizer(); //pour faire fonctionner, ne pas renseigner de seuil de confiance
    //Ptr<face::FaceRecognizer> model = face::createFisherFaceRecognizer(0); //pour faire fonctionner, ne pas renseigner de seuil de confiance
    Ptr<cv::face::FaceRecognizer> model = face::createLBPHFaceRecognizer(1,8,16,16); //étudier influence des différents paramètres !
    
    model->train(images, labels);

    image=treatment(detectFace(image),true);
    
    int predicted_label = model->predict(image);
    cout << "label image reconnue :" << endl;
    cout << predicted_label << endl;
    if(predicted_label == -1){
        cout << "face not recognized..." << endl;
    }
}

