//============================================================================
// Name        : FaceExtraction.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : C++ project
//============================================================================

//Entrée : Matrice
//Sortie : Points caractéristiques
 
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"
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

Mat detectFace(Mat frame)
{
    //vérification du chargement des cascades (fichiers xml)
    if( !face_cascade.load(face_cascade_name)){
        cout << "error loading face_cascade" << endl;
    }
    if( !eyes_cascade.load(eyes_cascade_name)){
        cout << "error loading eye_cascade" << endl;
    }
    //face extraction
    Mat frame_gray;
    Mat faceROI;
    cv::cvtColor(frame, frame_gray, CV_BGR2GRAY);
    std::vector<Rect> faces; //contenu de face_cascade
    face_cascade.detectMultiScale(frame_gray,faces,1.1,2,0|CV_HAAR_SCALE_IMAGE, Size(30, 30));
    for(size_t i=0; i<faces.size(); i=i+1){
        faceROI = frame_gray(faces[i]);
    }
    return faceROI;
    
}