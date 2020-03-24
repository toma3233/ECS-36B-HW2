//Name: Tom Abraham
//Student ID: 917096660

#include "Aircraft.h"
#include <iostream>
using namespace std;

// Aircraft constructor that initializes numEng and nm by using an initializor list
Aircraft::Aircraft(int n, std::string name_str) : numEng(n), nm(name_str){
    // Declaring and intializing engines array
    hrs = new int[n];
    for(int i = 0; i < n; i++){
        *(hrs+i) = 0;
    }
};
// Destructor for Aircraft class
Aircraft::~Aircraft(void){
    delete hrs;
}

// A380 Constructor that initializes the numEng and and name_str using Aircraft constructor
A380::A380(std::string name_str) : Aircraft(4, name_str){
   
};
// B737 Constructor that initializes the numEng and and name_str using Aircraft constructor
B737::B737(std::string name_str): Aircraft(2, name_str){
};
// Returns the type of A380
const std::string A380::type(void) const{
    return "Airbus A380";
}
//Returns the type of B737
const std::string B737::type(void) const{
    return "Boeing 737";
}
//returns maximum hours of A380
const int A380::maxHours(void) const{
    return 750;
}
//returns the maximum hours of B737
const int B737::maxHours(void) const{
    return 500;
}
//returns the name of the Aircraft
const std::string Aircraft::name(void) const{
    return nm;
}
//returns the number of engines for the aircraft
int Aircraft::numEngines(void) const{
    return numEng;
}
//sets the number of hours for a specific engine on the aircraft
void Aircraft::setHours(int i, int h){
    *(hrs + (i-1)) = h;
}
//prints out the number of engines the aircraft contains and the number of hours on each engine
void Aircraft::print(void) const{
    int num = numEng;
    if (num == 4){
        std::cout << "Aircraft: " << nm << " type: Airbus A380 has 4 engines" << endl;
    }
    else{
        std::cout << "Aircraft: " << nm << " type: Boeing B737 has 2 engines" << endl;
    }
    for(int i = 0; i < num; i++){
        std::cout << "engine " << i + 1 << ": " << *(hrs + i) << " hours" << endl;
    }
}
//Prints the number of hours each engine has until maintenance is due
void Aircraft::printSchedule(void) const{
    int num = numEng;
    int max = 0;
    if (num == 4){
        max = 750;
    }
    else{
        max = 500;
    }
    std::cout << "Maintenance schedule for " << nm << endl;
    for(int i = 0; i < num; i++){
        if ((max - *(hrs + i)) < 0){
            std::cout << "engine " << i + 1 << ": maintenance due now!!" << endl;
        }
        else{
            std::cout << "engine " << i + 1 << ": maintenance due in " << (max - *(hrs + i)) << " hours" << endl;
        }
        
    }
}
//Creates new pointer to an aircraft object depending on the char received from input
Aircraft* Aircraft::makeAircraft(char ch, std::string name_str){
    if(ch == 'A'){
        Aircraft *plane = new A380(name_str);
        return plane;
    }
    else if (ch == 'B'){
        Aircraft *plane = new B737(name_str);
        return plane;
    }
    else{
        return 0;
    }
}