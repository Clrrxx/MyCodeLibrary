#include <iostream>
using namespace std;

//function hiding

class Base{
public:
    void display(){
        cout<<"Base Class show" <<endl;;
    }
};

class derived : public Base{
public:

    using Base::display; //must include this if u want to overload otherwise error
    void display(int a){
        cout << a<<endl;;
    }
};

int main(){
    derived d;
    d.display();
    d.display(10);
}