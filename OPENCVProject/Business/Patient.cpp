//============================================================================
// Name        : Patient.cpp
// Author      : IFREBAULT
// Version     :
// Copyright   : 
// Description : C++ project
//============================================================================

//classe principale : regroupe les infos sur un patient dans un objet

//#include<string>
//#include<ctime>

#include "Patient.h"
//#include "Picture.h"
//#include "Disease.h"

using namespace std;

/*cluster Patient::getDatas(int id) const{
}*/
    
Patient::Patient() {
    id = 1;
    name = "Toto";
    firstName = "Tata";
    gender = 'M';
    /*birthDate(00000000),*/;
    SSN = "0000000000000";
    address = " ";
    telephoneNumber= "0000000000";
        //constructeur
}
/*
const Disease& Patient::getDiseases(int id) const{ 
    return Disease();
}*/

    
Picture Patient::getPictures(int id) const{
    return Picture();
}
    
const string& Patient::getName() const{
    return name;
}
    
/*Patient::~Patient()
{
    //destructeur
}*/

