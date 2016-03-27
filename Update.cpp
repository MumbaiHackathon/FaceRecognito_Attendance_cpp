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

void Update(string InputFileName, string KnowledgeFileName)
{
    vector<Mat> ImageVector;
    vector<int> LabelVector;

    // Todo Read KnowledgeInputFile and load Recognition model

    // Todo Update if possible else retrain

    // Read Class CSV File to get list of students and their CSV files
    vector<vector<string>> ClassData = ReadCSVFile(InputFileName);
    for( int ii = 0 ; ii < ClassData.size() ; ii++ )
    {
        // Read Student CSV file to get list of his/her images
        vector<vector<string>> StudentData = ReadCSVFile(ClassData[ii][1]);
        for( int jj = 0 ; jj < StudentData.size() ; jj++ )
        {
            ImageVector.push_back(imread(StudentData[jj][0].c_str(),0));
            LabelVector.push_back(stoi(ClassData[ii][0]));
        }
    }

    /// Todo Create Recogintion model and train using training data.
    /// Save Model to KnowledgeOutputFile
}