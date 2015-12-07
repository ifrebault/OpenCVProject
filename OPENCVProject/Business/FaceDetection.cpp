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
#include "opencv2/face.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace cv;
using namespace std;

//variables globales
//attention, en cas d'erreur à la compilation, vérifier le chemin...
String face_cascade_name = "../../OpenCVProject/OPENCVProject/Business/haarcascade_frontalface_alt.xml";
String eyes_cascade_name = "../../OpenCVProject/OPENCVProject/Business/haarcascade_eye_tree_eyeglasses.xml";
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;
RNG rng(12345);

void recognise(Mat image){

    int num_components = 10;
    double threshold = 10;
    int radius=1;
    int neighbors=8;
    int grid_x=8;
    int grid_y=8;

    //todo : construction base à refaire une fois BDD dispo
    Mat img0 = treatment(imread("../../OpenCVProject/BDD jpg/img0.jpg"),false);
    Mat img1 = treatment(imread("../../OpenCVProject/BDD jpg/img1.jpg"),false);
    Mat img2 = treatment(imread("../../OpenCVProject/BDD jpg/img2.jpg"),false);
    Mat img3 = treatment(imread("../../OpenCVProject/BDD jpg/img3.jpg"),false);
    Mat img4 = treatment(imread("../../OpenCVProject/BDD jpg/img4.jpg"),false);
    Mat img5 = treatment(imread("../../OpenCVProject/BDD jpg/img5.jpg"),false);
    Mat img6 = treatment(imread("../../OpenCVProject/BDD jpg/img6.jpg"),false);
    Mat img7 = treatment(imread("../../OpenCVProject/BDD jpg/img7.jpg"),false);
    Mat img8 = treatment(imread("../../OpenCVProject/BDD jpg/img8.jpg"),false);
    //Mat img9 = treatment(imread("../../OpenCVProject/BDD jpg/img9.jpg"),false);
    Mat img10 = treatment(imread("../../OpenCVProject/BDD jpg/img10.jpg"),false);

    vector<Mat> images = {img0,img1,img2,img3,img4,img5,img6,img7,img8,img10};
    vector<int> labels = {0,1,2,3,4,5,6,7,8,10};
    
    //vérification du chargement des cascades (fichiers xml)
    if( !face_cascade.load(face_cascade_name)){
        cout << "error loading face_cascade" << endl;
    }
    if( !eyes_cascade.load(eyes_cascade_name)){
        cout << "error loading eye_cascade" << endl;
    }
    
    detectAndDisplay(treatment(image,false));
     
    /*
    Ptr<face::FaceRecognizer> model = face::createEigenFaceRecognizer(num_components, threshold);
    //Ptr<face::FaceRecognizer> model = face::createFisherFaceRecognizer(num_components, threshold);
    //Ptr<cv::face::FaceRecognizer> model = face::createLBPHFaceRecognizer(radius, neighbors, grid_x, grid_y, threshold);

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
    */

}

void detectAndDisplay(Mat frame_gray)
{
    std::vector<Rect> faces; //contenu de face_cascade
    
    face_cascade.detectMultiScale(frame_gray,faces,1.1,2,0|CV_HAAR_SCALE_IMAGE, Size(30, 30));
    
    for(size_t i=0; i<faces.size(); i=i+1)
    {
        Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
        ellipse(frame_gray, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0);
        //Regions Of Interest : visage
        Mat faceROI = frame_gray(faces[i]);
    }
    //résultat : debug uniquement
    imshow("face detection",frame_gray);
    waitKey(0);
}
