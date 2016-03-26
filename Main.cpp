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
        cout << "  syntax : " << argv[0] << "train <InputFile> <KnowledgeOutputFile>" << endl << endl;
        cout << "predict" << endl;
        cout << "  syntax : " << argv[0] << "predict <InputFile> <KnowledgeInputFile> <SuccessOutputFile> <ErrorOutputFile>" << endl << endl;
        cout << "update" << endl;
        cout << "  syntax : " << argv[0] << "update <InputFile> <KnowledgeFile>" << endl << endl;
    }
    return 0;
}