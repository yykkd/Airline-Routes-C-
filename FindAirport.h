//
// Created by Yasmin on 12/15/2022.
//
#include "iostream"
#include "string"
#include "cstring"
#include "map"
#include "vector"
#include "fstream"
#include "regex"
using namespace std;

#ifndef AIRLINEROUTESTWO_FINDAIRPORT_H
#define AIRLINEROUTESTWO_FINDAIRPORT_H
class FindAirport {
private:
    vector<string> matching_airports;
    vector<string> split(string s, regex r);

public:
    vector<string> getMatchingAirports();
    FindAirport(string city_name, string country_name);
    string country;
    string city;

private:
    void readMatchingAirports();

};
#endif //AIRLINEROUTESTWO_FINDAIRPORT_H
