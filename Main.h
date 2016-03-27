#ifndef MAIN_H
#define MAIN_H

#include<vector>
#include<string>

#include "CSV.cpp"
#include "Train.cpp"
#include "Predict.cpp"
#include "Update.cpp"

using namespace std;

vector<vector<string>> ReadCSVFile(string FileName);
void Train(string InputFileName, string KnowledgeOutputFileName);
void Predict(string InputFileName, string KnowledgeInputFileName, string SuccessOutputFileName, string ErrorOutputFileName);
void Update(string InputFileName, string KnowledgeFileName);
#endif