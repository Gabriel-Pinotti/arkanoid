#include "saving.h"
#include "global.h"
#include <string>
#include <vector>
#include <fstream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <iostream>
using namespace std;

string getDate(){
    auto now = chrono::system_clock::now();
    time_t now_time = std::chrono::system_clock::to_time_t(now);
    tm* local_time = std::localtime(&now_time);
    stringstream tempss;
    tempss << put_time(local_time, "%d/%m/%Y");
    string currentDate = tempss.str(); // DD/MM/YYYY
    return currentDate;
}

void saveScore(string name, int pts, int dif){
    ofstream savefile("./data/saves.txt", ios::app);
    if (savefile.is_open()) {
        savefile << name << "|" << pts << "|" << dif << "|" << getDate() << endl;
        savefile.close();
    }
}

vector<string> formatScore(const string& str) {
    vector<string> parts;
    string current = "";

    for (char c : str) {
        if (c == '|') {
            parts.push_back(current);
            current = "";
        } else {
            current += c;
        }
    }
    parts.push_back(current); // final one

    if (parts[2] == "1") parts[2] = "Fácil";
    else if (parts[2] == "2") parts[2] = "Médio";
    else if (parts[2] == "3") parts[2] = "Difícil";
    
    return parts;
}


vector<string> readScoresFile() {
    ifstream savefile("./data/saves.txt");
    vector<string> lineVector;

    string currentLine;
    while (getline(savefile, currentLine)) {
        lineVector.push_back(currentLine);
    }

    return lineVector;
}

void sortScores(vector<string>& scoreList) {
    sort(scoreList.begin(), scoreList.end(), [](const string& a, const string& b) {

        vector<string> A = formatScore(a);
        vector<string> B = formatScore(b);

        int pointsA = stoi(A[1]);
        int pointsB = stoi(B[1]);

        // 1 - points
        if (pointsA != pointsB)
            return pointsA > pointsB;

        // 2 - difficulty
        auto diffToInt = [](const string& s) { // data formatting for comparision
            if (s == "Fácil") {
                return 1;
            } else if (s == "Médio") {
                return 2;
            } else if (s == "Difícil") {
                return 3;
            }
            return 0;
        };

        int difA = diffToInt(A[2]);
        int difB = diffToInt(B[2]);

        if (difA != difB)
            return difA > difB;

        return false; // ptsA == ptsB && difA == difB
    });
}
