//============================================================================
// Name        : FaceRecognition.cpp
// Author      : IFREBAULT
// Version     :
// Copyright   : http://docs.opencv.org/2.4/modules/contrib/doc/facerec/facerec_tutorial.html
// Description : C++ project
//============================================================================

//Entrée : Image
//Sortie : Matrice

/*
 ETAPES :
 - Training avec la base dispo
 - Récupération du visage seul
 - Application de l'algo
 - sortie du résultat
 */

#define TESTU

#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "PreTreatment.h"
#include "FaceRecognition.h"
#include "FaceExtraction.h"
#include "SendMatrixToBusiness.h"


#include "opencv2/face.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace cv;
using namespace std;


int recognise(Mat image){
    //à supprimer à terme
    int size_base=20;
    int avoid = 13;
    
    int predicted_label = -1;
    double predicted_confidence = 0.0;
    double threshold = 16500;
    
    vector<string> names;
    vector<int> labels;
    vector<Mat> images;
   
    //todo : construction base à refaire une fois BDD dispo
    names = getNames();
    labels = getIds();
    
    //construction du vecteur de noms de fichier temporaire :
    for(int i=0; i < size_base; i=i+1){
        std::string iString = std::to_string(i);
        names.push_back("../../OpenCVProject/BDDjpg/img" + iString + ".jpg");
        labels.push_back(i);
    }
    //vérification de la cohérence de la base
    if (names.size()!=labels.size()){
        cout << "Issue in the recognition base : images sizes != labels sizes"<< endl;
    }
    
    for(int i=0; i < size_base; i=i+1){
        Mat temp=imread(names[i]);
        images.push_back(treatment(detectFace(temp),true));
    }
    //à supprimer à terme
    images.erase(images.begin()+avoid);
    labels.erase(labels.begin()+avoid);
    names.erase(names.begin()+avoid);
    
    Ptr<face::FaceRecognizer> model = face::createEigenFaceRecognizer();
    
    model->train(images,labels);
    
    image=treatment(detectFace(image),true);
    
    model->predict(image, predicted_label, predicted_confidence);
    
    if (predicted_confidence > threshold){
        predicted_label=-1;
    }
    
    //utile pour debug sans IHM, à supprimer à terme
    if(predicted_label == -1){
        cout << "face not recognized..." << endl;
    }else{
        cout << "label image reconnue :" << endl;
        cout << predicted_label << endl;
        imshow("image reconnue",treatment(imread(names[findInVector(labels, predicted_label)]),false));
        waitKey(0);
    }
    
    return predicted_label;
}

int findInVector(vector<int> vector, int a){
    for (int i=0; i < vector.size(); i=i+1){
        if (vector[i]==a){
            return i;
        }
    }
    return -1;
}

 #ifdef TESTU

void TestU_recognise (Mat image)
 {
 
 Mat imageTest = imread("../../OpenCVProject/BDDjpg/img13.jpg");
 int test = recognise(imageTest);
 
 if(test==15)
 {
 std::cout << "TU FaceRecognition : image reconnue \n";

 }
 else
 {
 std::cout << "TU FaceRecognition : attention image non reconnue \n";

 
 }

 }
 
 #endif