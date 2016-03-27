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

    // Create and Load Face Cascade classifier
    CascadeClassifier FaceCascade("/usr/local/share/OpenCV/haarcascades/haarcascade_frontalface_default.xml");

    if ( FaceCascade.empty() )
    { 
        cout << "Error loading cascade file" << endl;
        return;
    }
    
    // Read Student CSV file to get list of his/her images
    cout << "Reading CSV File" << endl;
    vector<vector<string>> StudentData = ReadCSVFile(InputFileName);
    cout << "Done Reading CSV File" << endl;

    cout << "Reading Images" << endl;
        for( int jj = 0 ; jj < StudentData.size() ; jj++ )
    {
        Mat Raw = imread(StudentData[jj][1].c_str(),0);
        vector<Rect> Faces;

        //Detect face using cascade classifier
        FaceCascade.detectMultiScale(Raw, Faces, 1.1, 2, 0, Size(0,0), Size(2048,2048));

        if(Faces.size() != 1) continue;

        // Crop Image according to the detected face
        Mat Cropped = Raw(Faces[0]);
               
        // Resize the cropped Image to predecided size
        Mat Resized;
        resize(Cropped,Resized,IMAGE_SIZE);
        //Create Training Vectors
        ImageVector.push_back(Resized);
        LabelVector.push_back(stoi(StudentData[jj][0]));
    }

    /// Todo Create Recogintion model and train using training data.
    Ptr<FaceRecognizer> RecognitionModel = createFisherFaceRecognizer();
    RecognitionModel->train(ImageVector,LabelVector);

    /// Save Model to KnowledgeOutputFile
    RecognitionModel->save(KnowledgeOutputFileName);
    cout << "Done Training" << endl;
}