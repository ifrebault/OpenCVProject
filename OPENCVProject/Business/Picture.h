#ifndef DEF_PICTURE
#define DEF_PICTURE

#include <iostream>
#include <string>

class Picture{
    
private:
    int id;
    int idPatient;
    std::string fileName;
    
    
public:
    Picture();
    std::string getImage(int id) const;
    
};

#endif