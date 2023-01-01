//
// Created by Yasmin on 12/15/2022.
//

#include "string"
#include "iostream"
#include "vector"
#include "regex"
#include "fstream"
using namespace std;

#ifndef AIRLINEROUTESTWO_READWRITE_H
#define AIRLINEROUTESTWO_READWRITE_H
vector<string> readFile();
vector<string> split(string s, regex r);
#endif //AIRLINEROUTESTWO_READWRITE_H
