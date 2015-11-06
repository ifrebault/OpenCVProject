#ifndef DEF_DISEASE
#define DEF_DISEASE

#include <iostream>
#include<string>

class Disease{
    
private:
    int id;
    int idPatient;
    std::string disease;
    std::string treatment;
    
public:
    Disease();
    std::string getDisease(int id) const;
    std::string getTreatment(int id) const;
    std::string getDiseases(int idPatient) const;
};

#endif