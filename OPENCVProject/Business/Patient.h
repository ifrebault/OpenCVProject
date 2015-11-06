#ifndef DEF_PATIENT
#define DEF_PATIENT

#include <iostream>
#include <string>
#include <ctime>


#include "Picture.h"
#include "Disease.h"

class Patient{
    
private:
    int id;
    std::string name;
    std::string firstName;
    char gender;
    //struct tm birthDate;
    std::string SSN;
    std::string address;
    std::string telephoneNumber;
    
public:
    //cluster getDatas(int id) const;
    Patient();
    std::string getName() const;
    Disease getDiseases(int id) const;
    Picture getPictures(int id) const;
    //~Patient();
    
};

#endif