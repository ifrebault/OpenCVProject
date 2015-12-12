//============================================================================
// Name        : Disease.cpp
// Author      : IFREBAULT
// Version     :
// Copyright   :
// Description : C++ project
//============================================================================

//#include<string>
#include"Disease.h"

using namespace std;

    Disease::Disease() : id(-1), idPatient(-1), disease(" "), treatment(" "){
        //constructeur
    }
    string Disease::getDisease(int id) const{
        return disease;
    }
    
    string Disease::getTreatment(int id) const{
        return treatment;
    }
    
    string Disease::getDiseases(int idPatient) const{
        return "empty";
    }
    
