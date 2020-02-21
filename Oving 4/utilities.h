#pragma once

int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimesRef(int& startValue, int& increment, int& numTimes);
void swapNumbers(int& a, int& b);
void randomizeVector(vector<int>& vektor, int n);
int randomWithLimits(int nedreGrense, int ovreGrense);
void sortVector(vector<int>& vektor);
double medianOfVector(const vector<int>& vektor);
string randomizeString(int AntallTegn, char nedregrense, char ovregrense);
string readInputToString(char nedregrense, char ovregrense, int n);
int countChar(string s, char c); 




