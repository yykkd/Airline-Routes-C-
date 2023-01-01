#include <iostream>
#include "Read.h"
#include "FindAirport.h"
#include "AirlineManager.h"
#include "RouteFinder.h"

void writeFile(vector<vector<string>> vector1, RouteFinder finder);

int main() {
    vector<string> file_contents = readFile();
    string start_city = file_contents.at(0);
    string start_country = file_contents.at(1);
    string destination_city = file_contents.at(2);
    string destination_country = file_contents.at(3);

    vector<vector<string>> all_paths;

    FindAirport starting = FindAirport(start_city, start_country);
    FindAirport destination = FindAirport(destination_city, destination_country);

    vector<string> starting_airports = starting.getMatchingAirports();
    vector<string> destination_airports = destination.getMatchingAirports();

    AirlineManager air = AirlineManager();
    vector<string> available_airlines = air.getAvailableAirlines();

    RouteFinder route = RouteFinder(available_airlines);
    route.findStartRoutes(starting_airports);

    bool found1 = false;
    bool found_multiple_paths = false;

    for(string airport: destination_airports){
        found1 = route.findOneStepPath(airport);
        found_multiple_paths = route.findMultiPath(airport);
    }

    if (found1 || found_multiple_paths) {
        all_paths = route.path;
    } else{
        cout << "No route found";
        exit(0);
    }

    writeFile(all_paths, route);

    return 0;
}



void writeFile(vector<vector<string>> path, RouteFinder route){
    int numbering = 0;
    int total_stops = 0;
    string file_name;

    ofstream writing;
    cout << "Enter file output name" << endl;
    cin >> file_name;
    writing.open(file_name);


    vector<string> my_path = path[0];

    if(!writing){
        cout << "Cannot open file";
        exit(0);
    }

    for(int i =0; i < my_path.size() - 1; i++){
        numbering += 1;
        vector<string> airport_code_stops = route.getAirportidStops(my_path[i], my_path[i+1]);
        string airline_code = airport_code_stops[0];
        int stops = stoi(airport_code_stops[1]);
        total_stops+=stops;
        writing <<"\t" <<numbering << "." << airline_code << " from "<< my_path[i] << " to " << my_path[i+1]<< " " << stops << " stops" << "\n";
    }

    writing << "Total flights: "<< numbering<<"\n";
    writing << "Total additional stops: "<< total_stops<<"\n";

}
