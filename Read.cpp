//
// Created by Yasmin on 12/15/2022.
//

#include "Read.h"
vector<string> split(string s, regex r){
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

vector<string> readFile(){
    ifstream fin;
    fin.open(R"(C:\Users\Yasmin\CLionProjects\AirlineRoutesTwo\Accra_Winnipeg.txt)");

    string line1;
    string line2;

    string start_city, start_country;
    string destination_city, destination_country;

    string r = ",";

    getline(fin, line1);
    getline(fin, line2);

    vector<string> start = split(line1, regex(r));
    vector<string> stop = split(line2, regex(r));

    start_city = start[0];
    start_country = start[1].substr(1, start[1].size()-1);

    destination_city = stop[0];
    destination_country = stop[1].substr(1, stop[1].size()-1);


    if(start.size() > 2){
        int go = 0;
        string replaced_city = "";
        while(go < start.size() - 1) {
            if(go == start.size() - 2) {
                replaced_city += start[go];
            } else {
                replaced_city += start[go] + ",";
            }
            go++;
        }
        destination_city = replaced_city;
        destination_country = line2[2];
    }

    vector<string> individuals;

    individuals.push_back(start_city);
    individuals.push_back(start_country);
    individuals.push_back(destination_city);
    individuals.push_back(destination_country);

    fin.close();
    return individuals;
}
