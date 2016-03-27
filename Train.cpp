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

void Train(string InputFileName, string KnowledgeOutputFileName)
{
    vector<Mat> ImageVector;
    vector<int> LabelVector;

    // Read Student CSV file to get list of his/her images
    vector<vector<string>> StudentData = ReadCSVFile(InputFileName);
    for( int jj = 0 ; jj < StudentData.size() ; jj++ )
    {
        //Create Training Vectors
        ImageVector.push_back(imread(StudentData[jj][1].c_str(),0));
        LabelVector.push_back(stoi(StudentData[jji][0]));
    }

    /// Todo Create Recogintion model and train using training data.
    /// Save Model to KnowledgeOutputFile
}