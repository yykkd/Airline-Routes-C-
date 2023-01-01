//
// Created by Yasmin on 12/15/2022.
//

#include "string"
#include "map"
#include "vector"
#include "fstream"
#include "regex"
#include "iostream"
using namespace std;

#ifndef AIRLINEROUTESTWO_AIRLINEMANAGER_H
#define AIRLINEROUTESTWO_AIRLINEMANAGER_H
class AirlineManager{
private:
    vector<string> available_airlines;
    map<string, string> available_airlines_icao;

    string country;
    string airline_code;
    string icao_code;
    string is_active;

public:
    AirlineManager();
    vector<string> getAvailableAirlines();

private:
    void readFile();
    bool canFly(string active);
    vector<string> split(string s, regex r);
};
#endif //AIRLINEROUTESTWO_AIRLINEMANAGER_H
