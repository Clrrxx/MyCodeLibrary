#include <iostream>
using namespace std;

class Base{
protected:
    int value;
public:
    Base(int v);    //constructor declaration
};

//passing arguments to base class constructors
Base::Base(int v) : value(v){
    cout << "Val: " <<value <<endl;
    cout << "Base Constructed\n";
}

class Derived : public Base{
private:
    int extraVal;
public:
    Derived(int v1, int v2);
};

//into the derived constructor, pass Base class int v into V1 and extraval into V2
Derived::Derived(int v1, int v2) : Base(v1), extraVal(v2){
    cout << "Val: " <<value<<endl;
    cout << "Extra: " <<extraVal<<endl;
    cout << "derived constructed";
}

/*
if arguments are not passed thru the base class, will throw error, this is becuase the complier
does not know how to initialise the base class

WRONG CODE
Derived::Derived(int v1, int v2){
    value = v1;
    extraVal = v2;
    cout << "Val: " <<value<<endl;
    cout << "Extra: " <<extraVal<<endl;
    cout << "derived constructed";
}


*/

int main(){
    Derived d(10, 20);
    return 0;
}