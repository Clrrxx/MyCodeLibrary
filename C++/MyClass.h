#ifndef MYCLASS_H       //Head guards in C++, preprocessor directives that help to avoid errors that arise when the same
#define MYCLASS_H       //function is included/defined more than once (#pragma once also works)
class MyClass {
public:                 //member access specifier
    MyClass();          //default constructor
    MyClass(int a);     //parameterised constructor (overloaded constructors)
    //MyClass(): data(0){};
    //MyClass(int a): data(a){}
    ~MyClass();         //destructor => 

    void doSomething(); //member function

private:                //encapsulate the data variables (oop encapsulation)
    int data;
};

#endif // MYCLASS_H

//constructors cannot return a value and has no return type (no void), only used to initialize the data members
//never define more than one default constructor for a class (C++ only)

/*
Constructors can be initialised in 2 ways

Assignment way: 
MyClass::MyClass(){ data = 0;}  

initializer list way:
MyClass(int a): data(a){}

if there are more
MyClass(int a): data1(a), data2(b){}

*/

