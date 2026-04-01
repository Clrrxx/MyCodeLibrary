#include "MyClass.h"        //include header file
#include <iostream>

MyClass::MyClass(){ data = 0;}      //scope resolution op(::) used to indicate which class the fn belongs to
MyClass::MyClass(int a){data = a;}


MyClass::~MyClass(){
    std::cout<<"Bye"<<data<<std::endl;
}

void MyClass::doSomething(){
    std::cout<<"Do Something"<<std::endl;
}
