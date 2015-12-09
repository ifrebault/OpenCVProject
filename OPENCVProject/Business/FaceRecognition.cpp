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
#include <vector>

using namespace cv;
using namespace std;

void recognise(Mat image){

    int num_components = 0;
    double threshold = 0;
    int radius=1;
    int neighbors=8;
    int grid_x=8;
    int grid_y=8;
    
    int size_base=19;
    
    vector<string> names;
    vector<int> labels;
    vector<Mat> images;
    //todo : construction base à refaire une fois BDD dispo

    //construction du vecteur de noms de fichier temporaire :
    for(int i=0; i < size_base; i=i+1){
        std::string iString = std::to_string(i);
        names.push_back("../../OpenCVProject/BDDjpg/img" + iString + ".jpg");
        labels.push_back(i);
    }
    //vérification de la cohérence de la base
    if (names.size()!=labels.size()){
        cout << "Issue in the base : images sizes != labels sizes"<< endl;
    }
    
    for(int i=0; i < size_base; i=i+1){
        Mat temp=imread(names[i]);
        images.push_back(treatment(detectFace(temp),true));
    }
    
    //Ptr<face::FaceRecognizer> model = face::createEigenFaceRecognizer(); //pour faire fonctionner, ne pas renseigner de seuil de confiance
    //Ptr<face::FaceRecognizer> model = face::createFisherFaceRecognizer(0); //pour faire fonctionner, ne pas renseigner de seuil de confiance
    Ptr<cv::face::FaceRecognizer> model = face::createLBPHFaceRecognizer(2,8,16,16); //étudier influence des différents paramètres !
    
    model->train(images, labels);

    image=treatment(detectFace(image),true);
    
    int predicted_label = model->predict(image);
    
    if(predicted_label == -1){
        cout << "face not recognized..." << endl;
    }else{
        cout << "label image reconnue :" << endl;
        cout << predicted_label << endl;
        imshow("image reconnue",treatment(imread(names[predicted_label]),false));
        waitKey(0);
    }
    
}

