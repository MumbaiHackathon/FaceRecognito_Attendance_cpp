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

vector<vector<string>> ReadCSVFile(string FileName)
{
    ifstream CSVFile(FileName);
    string Line;
    vector<vector<string>> CSVData;
    // Read file line by line
    while (getline(CSVFile, Line))
    {
        vector<string> DataLine;
        stringstream LineStream(Line);
        string Cell;
        // Split Line at commas
        while(getline(LineStream, Cell, ','))
            DataLine.push_back(Cell);
        CSVData.push_back(DataLine);
    }
}

void WriteCSVFile(vector<vector<string>> CSVData, string FileName)
{
    ofstream CSVFile;
    CSVFile.open(FileName);
    for(int ii = 0 ; ii < CSVData.size() ; ii++ )
    {
        for(int jj = 0 ; jj < CSVData[ii].size() ; jj++ )
        {
            CSVFile << CSVData[ii][jj];
            if( jj != CSVData[ii].size() - 1)
                CSVFile << ",";
        }
        CSVFile << endl;
    }
}