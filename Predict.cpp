#include<sstream>
#include<fstream>
#include<iostream>
#include<vector>
#include<string>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

void Predict(string InputFileName, string KnowledgeInputFileName, string SuccessOutputFileName, string ErrorOutputFileName)
{
    // Todo Read KnowledgeInputFile and load Recognition model

    vector<Mat> RawImageVector;// contains uncropped images

    // Read Input CSV file to get list of class images
    // Crop them
    vector<vector<string>> RawImageNames = ReadCSVFile(InputFileName);
    for( int ii = 0 ; ii < RawImageNames.size() ; ii++ )
    {
        vector<Mat> CroppedImages;
        //
        // FIll this container with cropped faces of students from RawImageNames[ii]
        //
        for( int jj = 0 ; jj < CroppedImages.size() ; jj++ )
        {
          int Prediction = -1;
          double Confidence = 0.0;

          // Todo make prediction using Recognition model
          // Todo Do something with the prediction
        }
    }
}