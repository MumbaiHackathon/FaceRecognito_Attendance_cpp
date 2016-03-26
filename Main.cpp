#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;
int main(int argc, char** argv)
{
    if(argc < 4)
    {
        cout << argv[0] << endl;
        cout << "Usage : <command> [<args>]" << endl;
        cout << "List of commands :" << endl << endl;
        cout << "train" << endl;
        cout << "  syntax : " << argv[0] << " train <InputFile> <KnowledgeOutputFile>" << endl;
        cout << "predict" << endl;
        cout << "  syntax : " << argv[0] << " predict <InputFile> <KnowledgeInputFile> <SuccessOutputFile> <ErrorOutputFile>" << endl;
        cout << "update" << endl;
        cout << "  syntax : " << argv[0] << " update <InputFile> <KnowledgeFile>" << endl;
        return -1;
    }
    if(string(argv[1]) == "train") cout << "Training" << endl;
    else if(string(argv[1]) == "predict") cout << "Predicting" << endl;
    else if(string(argv[1]) == "update") cout << "Updating" << endl;
    else
    {
        cout << "Invalid Command" << endl;
        return -1;
    }
   return 0;
}