//============================================================================
// Name        : Picture.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : C++ project
//============================================================================

//#include<string>

#include"Picture.h"

using namespace std;

    Picture::Picture() : id(-1), idPatient(-1),fileName(" "){
        //constructeur
    }
    string Picture::getImage(int id) const{
        return fileName;
    }
    
    
