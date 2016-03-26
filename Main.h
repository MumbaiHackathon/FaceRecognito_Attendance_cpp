#ifndef MAIN_H
#define MAIN_H

#include<vector>
#include<string>

#include "CSV.cpp"
#include "Train.cpp"
#include "Predict.cpp"

using namespace std;

vector<vector<string>> ReadCSVFile(string FileName);
void Train(string InputFileName, string KnowledgeOutputFileName);
#endif