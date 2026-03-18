#include <iostream>
using namespace std;
// TO-DO: Write your functions here
template <class T>
T calArea(T side){
    return side*side;
}

template <class T>
T calArea(T length, T width){
    return length*width;
}
//every template requires its own template method;
template <class T>
T calArea(T breadth1, T breadth2, T height){
    return 0.5*(breadth1+breadth2)*height;
}


int main() {
    // Test cases
    int side1 = 5;
    cout << "Area of Square: " << calArea(side1) << endl;

    double side2 = 11.11;
    cout << "Area of Square: " << calArea(side2) << endl;
    
    int length1 = 10, width1 = 20;
    cout << "Area of Rectangle: " << calArea(length1, width1) << endl;
    
    float length2 = 23.4, width2 = 10.8;
    cout << "Area of Rectangle: " << calArea(length2, width2) << endl;
    
    long b1 = 20, b2 = 40, height = 10;
    cout << "Area of Trapezoid: " << calArea(b1, b2, height) << endl;
    return 0;
}
