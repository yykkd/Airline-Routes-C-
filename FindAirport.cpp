//
// Created by Yasmin on 12/15/2022.
//

#include "FindAirport.h"


FindAirport::FindAirport(string city_name, string country_name) {
    this->city = city_name;
    this->country = country_name;
}


void FindAirport::readMatchingAirports(){
    ifstream fin;
    fin.open(R"(C:\Users\Yasmin\CLionProjects\AirlineRoutes\airports.csv)");

    string line;

    vector<string> split_line;
    string airport_city;
    string airport_country;
    string icao_code;

    while(!fin.eof()){
        getline(fin, line);
        split_line = FindAirport::split(line, regex(",(?=(?:[^\"]*\"[^\"]*\")*[^\"]*$)"));

        airport_city = split_line[2];
        airport_country = split_line[3];
        icao_code = split_line[4];

        if(airport_city == city && airport_country == country && !(icao_code == "\\N")){
            matching_airports.push_back(icao_code);
            break;
        }
    }
}

vector<string> FindAirport::getMatchingAirports() {
    readMatchingAirports();
    return this->matching_airports;
}


vector<string> FindAirport::split(string s, regex r){
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


