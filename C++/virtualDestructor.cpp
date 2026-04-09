#include <iostream>
using namespace std;

class Animal{
public:
    Animal(){cout <<"animal\n";}
    virtual ~Animal(){cout << "destroy ani\n";}
};

class dog : public Animal{
public: 
    dog():Animal(){cout <<"dog\n";}

    ~dog(){cout<<"dog delete\n";}
};

int main(){
    Animal  *myani = new dog();
    delete myani;
    myani = nullptr;
    return 0;
}

//derived destructor is not called as it is statically binded
//so we use virtual 