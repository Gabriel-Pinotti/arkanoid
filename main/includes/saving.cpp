#include "saving.h"
#include "global.h"
#include <string>
#include <fstream>
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

string getDate(){
    auto now = chrono::system_clock::now();
    time_t now_time = std::chrono::system_clock::to_time_t(now);
    tm* local_time = std::localtime(&now_time);
    stringstream tempss;
    tempss << put_time(local_time, "%d-%m-%Y");
    string currentDate = tempss.str(); // DD-MM-YYYY
    return currentDate;
}

void saveScore(string name, int pts, int dif){
    ofstream savefile("./data/saves.txt", ios::app);
    if (savefile.is_open()) {
        savefile << name << "," << pts << "," << dif << "," << getDate() << endl;
        savefile.close();
    }
}
