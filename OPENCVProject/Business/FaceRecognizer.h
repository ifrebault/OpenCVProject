#ifndef DEF_PICTURE
#define DEF_PICTURE

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <array>

#include "opencv2/opencv.hpp"
#include "opencv2/core.hpp"


using namespace std;
//using namespace cv;

class FaceRecognizer : public cv::Algorithm
{
public:
    //! virtual destructor
    virtual ~FaceRecognizer() {}
    
    // Trains a FaceRecognizer.
    virtual void train(cv::InputArray src, cv::InputArray labels) = 0;
    
    // Updates a FaceRecognizer.
    virtual void update(cv::InputArrayOfArrays src, cv::InputArray labels);
    
    // Gets a prediction from a FaceRecognizer.
    virtual int predict(cv::InputArray src) const = 0;
    
    // Predicts the label and confidence for a given sample.
    virtual void predict(cv::InputArray src, int &label, double &confidence) const = 0;
    
    // Serializes this object to a given filename.
    virtual void save(const std::string& filename) const;
    
    // Deserializes this object from a given filename.
    virtual void load(const std::string& filename);
    
    // Serializes this object to a given cv::FileStorage.
    virtual void save(cv::FileStorage& fs) const = 0;
    
    // Deserializes this object from a given cv::FileStorage.
    virtual void load(const cv::FileStorage& fs) = 0;
    
    // Sets additional information as pairs label - info.
    void setLabelsInfo(const std::map<int, string>& labelsInfo);
    
    // Gets string information by label
    string getLabelInfo(const int &label);
    
    // Gets labels by string
    vector<int> getLabelsByString(const string& str);
};

#endif