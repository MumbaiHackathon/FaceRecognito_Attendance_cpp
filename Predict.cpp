#include<sstream>
#include<fstream>
#include<iostream>
#include<vector>
#include<string>
#include <opencv2/core.hpp>
#include <opencv2/face.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

using namespace std;
using namespace cv;
using namespace cv::face;

void Predict(string InputFileName, string KnowledgeInputFileName, string SuccessOutputFileName, string ErrorOutputFileName)
{
    // Read KnowledgeInputFile and load Recognition model
    Ptr<FaceRecognizer> RecognitionModel = createFisherFaceRecognizer();
    RecognitionModel->load(KnowledgeInputFileName);

    vector<Mat> RawImageVector;// contains uncropped images

    // Read Input CSV file to get list of class images
    // Generate RawImageVector from images
    vector<vector<string>> RawImageNames = ReadCSVFile(InputFileName);
    for( int ii = 0 ; ii < RawImageNames.size() ; ii++ )
    {
        // Resize Image
        Mat Raw = imread(RawImageNames[ii][0].c_str(),0);
        Mat Resized;
        resize(Raw,Resized,IMAGE_SIZE);
        
        RawImageVector.push_back(Resized);
    }

    // Make Prediction and Confidence vector
    vector<int> PredictionVector;// contains uncropped images
    vector<double> ConfidenceVector;// contains uncropped images

    //Iterate over all images, make predictions and fill PredictionVector and ConfidenceVectors
    for( int ii = 0 ; ii < RawImageVector.size() ; ii++ )
    {
        if( ii % 100 == 0) cout << ii << "/" << RawImageVector.size() << endl;
        int Prediction = -1;
        double Confidence = 0.0;
        RecognitionModel->predict(RawImageVector[ii],Prediction, Confidence);
        cout << RawImageNames[ii][0] << " " << Prediction << " " << Confidence <<endl;
        PredictionVector.push_back(Prediction);
        ConfidenceVector.push_back(Confidence);
    }
}