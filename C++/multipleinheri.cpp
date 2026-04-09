/*
in java, cannot inherit from multiple base classes, must use interface
C++ allows for multiple inheritance, B inherits from A and C
*/

#include <iostream>
using namespace std;

class Vehicle{
public:
    Vehicle(){ cout <<"Veh Constr: \n";}
    ~Vehicle(){cout<<"Veh destro \n";}
};

class fourweels{
public:
    fourweels(){cout <<"Four wheel constructed\n";}
    ~fourweels(){cout <<"four wheel destroyed\n";}
};

//car inherits from 2 base classes
class Car : public Vehicle, public fourweels{
public:
    Car(){cout <<"car constructed\n";}
    ~Car(){cout <<"car destroyed\n";}
};

int main(){
    Car mycar;
    return 0;
}

//constructors are called in the sequence they are inherited from, -> car inherits from
//vehicle first so vehicle constructors are called first