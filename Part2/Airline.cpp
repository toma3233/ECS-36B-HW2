//Name: Tom Abraham
//Student ID: 917096660

#include "Airline.h"
#include <iostream>
using namespace std;

/*Airline constructor that takes in 3 parameters (number of each type of plane), and uses 
  uses initializor list to initialize nAirplanes.*/
Airline::Airline(int nA321, int nB777, int nB787): nAirplanes(nB787 + nB777 + nA321){
    airplaneList = new Airplane*[nAirplanes];
    //Adds nA321 airplanes to list
    for(int i = 0; i < nA321; i++){
        Airplane* plane = new Airplane(10);
        airplaneList[i] = plane;
        cout << "Airplane " << i + 1 << " maximum load 10" << endl;
    }
    //Adds nB777 airplanes to list
    for(int i = nA321; i < (nA321 + nB777); i++){
        Airplane* plane = new Airplane(32);
        airplaneList[i] = plane;
        cout << "Airplane " << i + 1 << " maximum load 32" << endl;
    }
    //Adds nB787 airplanes to the list
    for(int i = (nA321 + nB777); i < (nA321 + nB777 + nB787); i++){
        Airplane* plane = new Airplane(40);
        airplaneList[i] = plane;
        cout << "Airplane " << i + 1 << " maximum load 40" << endl;
    }
};
//adds containers to the first plane in the list that can handle it, prints error message if no plane can handle shipment
void Airline::addShipment(int size){
    int added = 0;
    for(int i = 0; i < nAirplanes; i++){
        int space = ((airplaneList[i])->maxLoad()) - (airplaneList[i]->currentLoad());
        if(size <= space){
            airplaneList[i]->addContainers(size);
            added = 1;
            cout << size << " containers added to airplane " << i + 1 << endl;
            break;
        }
       
    }
    //Error message in case no plane can fit the shipment
    if(added == 0){
        cout << " could not fit " << size << " containers" << endl;
    }
    
}
//Prints a list of airplanes with their current and maximum load. Empty airplanes not included.
void Airline::printSummary(void){
    cout << "Summary:" << endl;
    for(int i = 0; i < nAirplanes; i++){
        if(airplaneList[i]->currentLoad() == 0){
            continue;
        }
        else{
            cout << "airplane " << i + 1 << " " << airplaneList[i]->currentLoad() << "/" << airplaneList[i]->maxLoad() << endl;
        }
    }
}
