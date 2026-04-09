#include <iostream>
#include <cmath>
#include <type_traits>
#include <vector>
using namespace std;

//abstract Class
class Shape{
protected:
    double area;
public:

    Shape(){cout<< "Shape Constructed"<<endl;}

    virtual ~Shape(){cout << "Shape Destroyed"<<endl;}
    virtual double calArea() = 0;

    double getArea(){
        return area;
    }
};

class Circle:public Shape{
private:
    double radius;
public:
    Circle(double radius){
        this->radius = radius;
        cout<< "Circle Constructed"<<endl;
    }
    ~Circle(){cout<< "Circle Destroyed"<<endl<<endl;}

    double calArea() override{
        area = M_PI * radius * radius;
        return area;
    }
};

class Rectangle:public Shape{
private:
    double width;
    double height;
public:
    Rectangle(double width, double height){
        this->height = height;
        this->width = width;
        cout<< "Rectangle Constructed"<<endl;
    }
    ~Rectangle(){cout<< "Rectangle Destoryed"<<endl<<endl;}

    double calArea() override{
        area = width * height;
        return area;
    }
};

int main() {
    // --- Direct stack allocation ---
    cout << "\n=== Stack Objects ===" << endl;
    Circle c(5.0);
    Rectangle r(4.0, 6.0);

    c.calArea();
    r.calArea();

    cout << "Circle area:    " << c.getArea() << endl;
    cout << "Rectangle area: " << r.getArea() << endl;

    // --- Polymorphic heap allocation via base pointer ---
    cout << "\n=== Polymorphic Dispatch ===" << endl;
    vector<Shape*> shapes;
    shapes.push_back(new Circle(3.0));
    shapes.push_back(new Rectangle(7.0, 2.0));
    shapes.push_back(new Circle(1.0));

    for (Shape* s : shapes) {
        cout << "Area: " << s->calArea() << endl;
    }

    // --- Cleanup: virtual destructor ensures correct derived dtor is called ---
    cout << "\n=== Cleanup ===" << endl;
    for (Shape* s : shapes) {
        delete s;
    }

    return 0;
}