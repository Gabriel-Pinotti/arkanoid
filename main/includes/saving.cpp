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

string getDate(){ // used in saveScore()
    auto now = chrono::system_clock::now();
    time_t now_time = std::chrono::system_clock::to_time_t(now);
    tm* local_time = std::localtime(&now_time);
    stringstream tempss;
    tempss << put_time(local_time, "%d/%m/%Y");
    string currentDate = tempss.str(); // DD/MM/YYYY
    return currentDate;
}


void saveScore(string name, int pts, int dif){ // save into file
    if(name.empty()) {
        name = "PLAYER";
    }
    ofstream savefile("./data/saves.txt", ios::app);
    if (savefile.is_open()) {
        savefile << name << "|" << pts << "|" << dif << "|" << getDate() << endl;
        savefile.close();
    }
}


vector<string> readScoresFile() { // return every save in a vector
    ifstream savefile("./data/saves.txt");
    vector<string> lineVector;

    string currentLine;
    while (getline(savefile, currentLine)) {
        if (currentLine != ""){ // skips if currentLine is empty
            lineVector.push_back(currentLine);
        }
    }

    return lineVector;
}


void sortScores(vector<string>& scoreList) { // sort saves by points and difficulty
    sort(scoreList.begin(), scoreList.end(), [](const string& a, const string& b) {

        vector<string> A = formatScore(a, false);
        vector<string> B = formatScore(b, false);

        int pointsA = stoi(A[1]);
        int pointsB = stoi(B[1]);
        int difA = stoi(A[2]);
        int difB = stoi(B[2]);

        // 1 - points
        if (pointsA != pointsB)
            return pointsA > pointsB;
        
        // 2 - difficulty
        if (difA != difB)
            return difA > difB;

        return false; // ptsA == ptsB && difA == difB
    });
}


vector<string> formatScore(const string& str, bool formatDifficulty = true) { // format specific save (vector with name, points, difficulty and date (in order))
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

    if (formatDifficulty){
        switch (stoi(parts[2])){
            case 1:
                parts[2] = "Fácil";
                break;
            case 2:
                parts[2] = "Médio";
                break;
            case 3:
                parts[2] = "Difícil";
                break;
        }
    }
    
    return parts;
}
