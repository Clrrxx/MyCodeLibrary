#include <iostream>
using namespace std;

//A derived class can be inherited from another class that is inherited from base
// A -> B -> C
class vehicle{
public: 
    vehicle(){cout<<"Vehicle constructor\n";}
    void showVeh(){
        cout << "This is veh\n";
    }
    ~vehicle(){cout << "Base Destroyed\n";}
};

class fourWheel : public vehicle{
public: 
    fourWheel(){cout<<"fourwheel constructor\n";}
    void showFourWheels(){
        cout<<"Veh has 4 wheels\n";
    }
    ~fourWheel(){cout<<"Level 1 destroyed\n";}
private:
    void showMe(){
        cout<<"LOL";
    }
};

class car : public fourWheel{
public: 
    car(){cout <<"car constructor\n";}
    void showCar(){
        cout << "This is car\n";
    }
    ~car(){cout <<"Level 2 destroyed\n";}
};

int main(){
    car myCar;
    myCar.showVeh();
    myCar.showFourWheels();
    myCar.showCar();
    //myCar.showMe(); inaccessible as it is private

    //mycar object can access all the superclass methods it inherits as long as they are
    //either protected or public
}

// car inherits from 4wheels which inherits from vehicle