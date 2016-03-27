#include<sstream>
#include<fstream>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <opencv2/core.hpp>
#include <opencv2/face.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include "Main.h"

using namespace std;
using namespace cv;
using namespace cv::face;


void Predict(string InputFileName, string KnowledgeInputFileName, string SuccessOutputFileName, string ErrorOutputFileName)
{
    cout<<"Reached here";
    // Read KnowledgeInputFile and load Recognition model
    Ptr<FaceRecognizer> RecognitionModel = createFisherFaceRecognizer();
    RecognitionModel->load(KnowledgeInputFileName);

    vector<Mat> RawImageVector;// contains uncropped images
    // Create and Load Face Cascade classifier
    CascadeClassifier FaceCascade("/usr/local/share/OpenCV/haarcascades/haarcascade_frontalface_default.xml");

    if ( FaceCascade.empty() )
    { 
        cout << "Error loading cascade file" << endl;
        return;
    }

    vector<vector<int>> PredictionMatrix;// contains uncropped images

    // Read Input CSV file to get list of class images
    // Generate RawImageVector from images
    vector<vector<string>> RawImageNames = ReadCSVFile(InputFileName);
    for( int ii = 0 ; ii < RawImageNames.size() ; ii++ )
    {
        Mat Raw;
        Mat Color = imread(RawImageNames[ii][0].c_str());
        cvtColor( Color, Raw, CV_BGR2GRAY );
        vector<Rect> Faces;

        //Detect faces using cascade classifier
        FaceCascade.detectMultiScale(Raw, Faces, 1.5, 5, 0, Size(100,100), Size(500,500));
    
        vector<int> PredictionVector;// contains uncropped images
        for( int jj = 0 ; jj < Faces.size() ; jj++ )
        {
            //Crop faces from group pictures
            Mat Cropped = Raw(Faces[jj]);

            // Resize Image
            Mat Resized;
            resize(Cropped,Resized,IMAGE_SIZE);
            int Prediction = -1;
            double Confidence = 0.0;
            RecognitionModel->predict(Resized,Prediction, Confidence);
            imwrite("./build/data/saved/" + to_string(ii) +  to_string(jj) + ".jpg", Resized );
            PredictionVector.push_back(Prediction);
        }
        PredictionMatrix.push_back(PredictionVector);
    }
    vector<vector<bool>> AttendanceMatrix;
    for(int ii = 0 ; ii < PredictionMatrix.size() ; ii++)
    {
        vector<bool> ImageAttendance;
        for(int jj = 0 ; jj < USERS ; jj++)
            ImageAttendance.push_back(find(PredictionMatrix[ii].begin(), PredictionMatrix[ii].end(), jj) != PredictionMatrix[ii].end());
        AttendanceMatrix.push_back(ImageAttendance);
    }
    
    
    for(int ii = 0 ; ii < AttendanceMatrix.size() ; ii++)
    {
        cout << RawImageNames[ii][0] << " ";
        for(int jj = 0 ; jj < AttendanceMatrix[ii].size() ; jj++)
            cout << AttendanceMatrix[ii][jj] << " ";
         cout<< endl;
    }
}