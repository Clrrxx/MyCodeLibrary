#include <iostream>
using namespace std;
class MyClass {
private:
    int value;

public:
    MyClass(int v) {value = v; } // Constructor

    // Overloading the + operator
    MyClass operator+(const MyClass& obj) const {   //const after the function specifies that it is a read only function and will not alter the obj

        return MyClass(value + obj.value);  //member val + input val -> use these 2 objects to create a new obj
    }

    // Function sum() that does the same as operator+
    MyClass sum(const MyClass& obj) const {

        return MyClass(value + obj.value);
    }

    void display() { cout<< "Value: " <<value<<endl; }
};

int main() {
    MyClass obj1(10), obj2(20);
    MyClass obj3 = obj1 + obj2; // Using overloaded + operator
    obj3.display();
    MyClass obj4 = obj1.sum(obj2); // Using sum() function
    obj4.display();
    return 0;
}