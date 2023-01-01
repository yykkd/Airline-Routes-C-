//
// Created by Yasmin on 12/15/2022.
//
#include "string"
#include <map>
#include <vector>
#include <fstream>
#include <cstring>
#include "regex"
#include "iostream"
#include "algorithm"
#include <utility>
using namespace std;

#ifndef AIRLINEROUTESTWO_ROUNTEFINDER_H
#define AIRLINEROUTESTWO_ROUNTEFINDER_H
class RouteFinder{
private:
    map<string, vector<string>> airport_graph;
    map<string, string> store_parent;
    string source_acode;
    vector<string> available_airlines;


public:
    explicit RouteFinder(vector<string> available_airlines);
    void findStartRoutes(vector<string> city_airports);
    bool findOneStepPath(string destination_airport);
    bool findMultiPath(string destination_airport);
    vector<vector<string>> path;
    vector<vector<string>> source_airports;
    vector<string> getAirportidStops(string start, string destination);

private:
    void createGraph(const vector<string>& available_airline);
    vector<string> split(string s, regex r);

    void  solutionPath(string destination);
};
#endif //AIRLINEROUTESTWO_ROUNTEFINDER_H
