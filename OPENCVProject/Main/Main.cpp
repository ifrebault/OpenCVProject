//#define TESTU

#include "opencv2/opencv.hpp"
#include "../Business/PreTreatment.h"
#include "../Business/FaceRecognition.h"

#include "./GUI/index.h"

using namespace std;
using namespace cv;
using namespace System;
using namespace System::Windows::Forms;

int main() {
    
    #ifdef TESTU // activation des tests unitaires
    std::cout << "this is opencvproject !\n";
    
    //lecture du fichier à analyser
    Mat imageTest = imread("../../OpenCVProject/BDDjpg/img15.jpg");
    TestU_recognise(imageTest);
    TestU_treatment(imageTest, false);
    #endif
	
	Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
	
    myOpenCV30::MyIndex form;
    Application::Run(%form);
	
	return 0;
    
    
}
