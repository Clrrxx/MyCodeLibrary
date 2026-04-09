#include <iostream>
using namespace std;


class BaseClass {
public: 
    BaseClass(){cout << "Base"<<endl;}
    ~BaseClass(){cout << "Base destroyed"<<endl;}
};

class DerivedClass : public BaseClass{       //<= Inheritance 
public: 
    DerivedClass(){cout <<"Derived" << endl;}
    ~DerivedClass(){cout << "Derived destroyed"<<endl; }
};

int main(){
    cout <<"Create Obj"<<endl;
    DerivedClass object;
    return 0;
}

/*
Every construcor called in C++ must have its respective destructor called inside it
use a regular ~ destructor takes no parameters and returns nothing. 

derived class does not inherit constructors, destructors or assignment operators from 
the base class, it has its own 

when an object of a derived class is created, base class constructors are executed first
then derived class that inherits it

when an object of derived is destroyed, the derived is first called then the base is called

derived CAN call constructors and assignment ops from the base class
*/