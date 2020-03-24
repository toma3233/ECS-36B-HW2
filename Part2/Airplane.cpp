//Name: Tom Abraham
//Student ID: 917096660

#include "Airplane.h"
#include <iostream>
using namespace std;
//Constructor that takes in maxContainers and initializes it using initialization list
Airplane::Airplane(int n) : maxContainers(n){
    //current number of containers when airplane object is created is 0
    numContainers = 0;

};
//Returns the max number of containers the airplane can carry
int Airplane::maxLoad(void){
    return maxContainers;
}
//Returns the current number of containers the plane is carrying 
int Airplane::currentLoad(void){
    return numContainers;
}
// Returns true if adding containers was successful, false if not. Throws exception if number of containers is negative
bool Airplane::addContainers(int n){
    if (n < 0){
        throw invalid_argument("must be positive");
    }
    else if((numContainers + n) <= maxLoad()){
        numContainers += n;
        return true;
    }
    return false;
}