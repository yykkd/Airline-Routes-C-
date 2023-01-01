//
// Created by Yasmin on 12/15/2022.
//

#include "RouteFinder.h"
bool RouteFinder::findOneStepPath(string destination_airport){
    for(vector<string> arr: source_airports){
        if(destination_airport.compare(arr[3]) == 0){
            vector<string> temp = {arr[2], arr[3]};
            path.push_back(temp);
            return true;
        }
    }
    return false;
}


bool RouteFinder::findMultiPath(string destination_airport) {
    string curr_airport = source_acode;
    vector<string> next_level;

    if(curr_airport.empty()){
        cout << "No solution found" << endl;
        exit;
    }
    if(curr_airport.compare(destination_airport) == 0){
        cout << "Already in city. Enter a different city" << endl;
        return true;
    }

    vector<string> explored;
    vector<string> frontier = {curr_airport};
    store_parent[curr_airport] = "None";

    while(frontier.size() > 0){
        string current_air = frontier[0];
        frontier.erase(frontier.begin());
        explored.push_back(current_air);

        next_level = airport_graph.at(current_air);
        for(string child: next_level){
            if(!(count(explored.begin(), explored.end(), child)) && !(count(frontier.begin(), frontier.end(), child))){
                store_parent[child] = current_air;

                if(child.compare(destination_airport) == 0){
                    solutionPath(destination_airport);
                    return true;
                }
                frontier.push_back(child);
            }
        }
    }
    return false;
}


void RouteFinder::findStartRoutes(vector<string> city_airports) {
    ifstream fin;
    fin.open(R"(C:\Users\Yasmin\CLionProjects\AirlineRoutes\routes.csv)");

    string line;
    vector<string> line_split;

    string airline_code;
    string airline_id;
    string source_airport_code;
    string destination_airport_code;
    string stops;

    while(!fin.eof()) {
        getline(fin, line);
        line_split = split(line, regex(","));

         vector<string> temp;

        if(count(city_airports.begin(), city_airports.end(), line_split[2])){
            source_acode = line_split[2];
            temp = {line_split[0], line_split[1], line_split[2], line_split[4], line_split[7]};
            source_airports.push_back(temp);
        }
    }
}


vector<string> RouteFinder::getAirportidStops(string start, string destination) {
    ifstream fin;
    fin.open(R"(C:\Users\Yasmin\CLionProjects\AirlineRoutes\routes.csv)");

    string line;
    vector<string> split_line;

    string airline_code;
    string airline_id;
    string source_airport_code;
    string source_airport_id;
    string destination_airport_code;
    string destination_airport_id;
    string codeshare;
    string stops;

    while(!fin.eof()){
        getline(fin, line);
        split_line = split(line, regex(","));
        airline_code = split_line[0];
        source_airport_code = split_line[2];
        destination_airport_code = split_line[4];
        stops = split_line[7];

        if(source_airport_code.compare(start) == 0  && destination_airport_code.compare(destination) == 0){
            vector<string> temp = {airline_code, stops};
            return temp;
        }
    }

    return {};
}

void RouteFinder::solutionPath(string destination) {
    vector<string> temp;

    while(destination != "None"){
        temp.insert(temp.begin(), destination);
        destination = store_parent.at(destination);

    }
    if(!(count(this->path.begin(), this->path.end(), temp))){
        path.push_back(temp);
    }
}

void RouteFinder::createGraph(const vector<string>& airlines) {
    ifstream fin;
    fin.open(R"(C:\Users\Yasmin\CLionProjects\AirlineRoutes\routes.csv)");

    string line;
    vector<string> line_split;

    while(!fin.eof()){
        getline(fin, line);
        line_split = split(line, regex(","));

        vector<string> temp;

        if(count(available_airlines.begin(), available_airlines.end(), line_split[0])){
            if(airport_graph.count(line_split[2]) < 1){
                airport_graph[line_split[2]] = {line_split[4]};
            }
            else{
                airport_graph.at(line_split[2]).push_back(line_split[4]);
            }
        }
    }
    fin.close();
}

RouteFinder::RouteFinder(vector<string> available_airlines) {
    this->available_airlines = std::move(available_airlines);
    createGraph(this->available_airlines);
}



vector<string> RouteFinder::split(string s, regex r) {
    vector<string> line;

    sregex_token_iterator iter(s.begin(), s.end(), r, -1);
    sregex_token_iterator end;

    while (iter != end)
    {
        line.push_back(*iter);
        ++iter;
    }

    return line;
}