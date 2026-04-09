#include <iostream>
using namespace std;
class Base{
public:
    virtual void display(){
        cout << "Base\n";
    }   //virtual key word is only in the function's declaration 
};  

// void Base::display(){"blah"} //if fn is outside the class, do not add virtual here

class derived : public Base{
public:
    virtual void display(){     //any overridden fn in derived is automatically virtual 
        cout << "Derived\n";    //but is good practice to declare them virtual
    }
};

int main(){
    Base a;
    derived b;

    a.display();
    b.display();


    Base *ptr = &a;
    ptr -> display();
    ptr = &b;
    ptr -> display();   //no virtual -> static binding takes place,
                        //ptr remains at base display()

                        //with virtual, runtime polymorphism can occur,
                        //ptr now points to derived display()
    return 0;
}

/*
virtual methods are methods that expect to be overriden in the derived class
this allows for dynamic binding where complier will bind at runtime instead of compile time
-> allows for runtime polymorphism


overriding vs redefining
overriding: 
-derived fn has the same fn name and the same argument list
-dynamically bound

redefining:
-same fn name, not necessarily same argument
-statically bound










*/