#ifndef SAVING
#define SAVING
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void saveScore(std::string name, int pts, int dif);

vector<string> readScoresFile();

vector<string> formatScore(const string& str);

void sortScores(vector<string>& scoreList);

#endif