//============================================================================
// Name        : Patient.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
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

Disease Patient::getDiseases(int id) const{
    return Disease();
}
    
Picture Patient::getPictures(int id) const{
    return Picture();
}
    
string Patient::getName() const{
    return name;
}
    
/*Patient::~Patient()
{
    //destructeur
}*/

