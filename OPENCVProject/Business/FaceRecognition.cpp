//============================================================================
// Name        : FaceRecognition.cpp
// Author      : IFREBAULT
// Version     :
// Copyright   : http://docs.opencv.org/2.4/modules/contrib/doc/facerec/facerec_tutorial.html
// Description : C++ project
//============================================================================

//Entrée : Image
//Sortie : Matrice
#include "opencv2/opencv.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "PreTreatment.h"
#include "FaceRecognition.h"
#include "FaceExtraction.h"
//#include "../Com/SendMatrixToBusiness.h"

#include "opencv2/face.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#include "my_global.h"
#include "mysql.h"
#define SERVER "127.0.0.1"
#define USER "root"
#define PASSWORD ""
#define DATABASE "classrecognition"

using namespace cv;
using namespace std;


int recognise(Mat image){

    int predicted_label = -1;
    double predicted_confidence = 0.0;
    double threshold = 16500;
    
    vector<string> names;
    vector<int> labels;
    vector<Mat> images;
    
	/* Com*/
	int size_base = 20;
    int avoid = 13;

    for(int i=0; i < size_base; i=i+1){
        std::string iString = std::to_string(i);
        names.push_back("../BDDjpg/img" + iString + ".jpg");
        labels.push_back(i);
    }

    if (names.size()!=labels.size()){
        cout << "Issue in the recognition base : images sizes != labels sizes"<< endl;
    }
    
    for(int i=0; i < size_base; i=i+1){
        Mat temp=imread(names[i]);
        images.push_back(treatment(detectFace(temp),true));
    }

    /*images.erase(images.begin()+avoid);
    labels.erase(labels.begin()+avoid);
    names.erase(names.begin()+avoid);*/
    
    Ptr<face::FaceRecognizer> model = face::createEigenFaceRecognizer();
    
    model->train(images,labels);
    
    image=treatment(detectFace(image),true);
    
    model->predict(image, predicted_label, predicted_confidence);
    
    if (predicted_confidence > threshold){
        predicted_label=-1;
    }
    
    if(predicted_label == -1){
        cout << "face not recognized..." << endl;
    }else{
        cout << "label image reconnue :" << endl;
        //cout << predicted_label << endl;

		MYSQL *connect; 
			connect=mysql_init(NULL); 
			if(!connect){
				fprintf(stderr,"MySQL Initialization Failed");
			}
 
			connect=mysql_real_connect(connect,SERVER,USER,PASSWORD,DATABASE,0,NULL,0);

			if(!connect){
				printf("Connection Failed!\n");
			}
	
			MYSQL_ROW row;  
			MYSQL_RES *result = NULL;

			string deleteData = "DELETE FROM insertdata ";
			mysql_query(connect, deleteData.c_str());
			

			string insertData = "INSERT INTO insertdata (id) VALUES ('''img" +  to_string(predicted_label);
			insertData.append("''')");

			mysql_query(connect, insertData.c_str());
        //imshow("image reconnue",treatment(imread(names[findInVector(labels, predicted_label)]),false));
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

