#include <iostream>
#include <math.h>
using namespace std;

class Shape{
public:
    //pure virtual function
    virtual double area() const = 0;
    virtual ~Shape(){};
};

class Circle : public Shape{
private:
    double radius;

public:
    Circle(double r) : radius(r){}
    
    //override the pure virtual function
    double area() const override{
        return M_PI * radius * radius;
    }
};

int main(){
    //Shape s; CANNOT INSTANTIATE SHAPE DIRECTLY SINCE IT IS A PURE VIRTUAL FN
    Shape * shapeptr = new Circle(1.0); //must do this
    cout << "Circle area: " << shapeptr -> area() <<endl;
    delete shapeptr;
    shapeptr = nullptr;
    return 0;

}

/*
an abstract class is a class that cannot be used to instantiate objects 
A class becomes abstract class when one of its member fns is a pure virtual function 
*/