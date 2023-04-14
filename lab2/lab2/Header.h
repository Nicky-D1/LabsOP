#pragma once
#include <iostream>
#include <string>
#include <fstream>


using namespace std;

struct BusRoute {
    string destination;
    int dep_hour;
    int dep_min;
    int duration_hour;
    int duration_min;
};

int OpenAndAddDataFile(string fileName);
int DeleteTrip(string fileName, int x);
void removeFileIfExists(const string& fileName);