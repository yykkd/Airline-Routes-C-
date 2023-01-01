//
// Created by Yasmin on 12/15/2022.
//

#include "AirlineManager.h"

AirlineManager::AirlineManager(){
    readFile();
}

void AirlineManager::readFile() {
    string iata_code;
    string icao_code;
    string active;

    string line;
    vector<string> split_line;

    ifstream fin;
    fin.open(R"(C:\Users\Yasmin\CLionProjects\AirlineRoutes\airlines.csv)");

    while (!fin.eof()) {
        getline(fin, line);

        split_line = split(line, regex(","));

        if(split_line.size() > 1){
            iata_code = split_line[3];
            icao_code = split_line[4];
            active = split_line[7];

            if (canFly(active) && !iata_code.empty()) {
                available_airlines_icao.insert({iata_code, icao_code});
                available_airlines.push_back(iata_code);
            }

        }
    }
}


bool AirlineManager::canFly(string active) {
    return active == "Y";
}

vector<string> AirlineManager::getAvailableAirlines(){
    return available_airlines;
}

vector<string> AirlineManager::split(string s, regex r) {
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