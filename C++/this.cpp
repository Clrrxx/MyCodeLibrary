#include <iostream>
using namespace std;

class MyClass {
private:
    int number;

public:
    // Constructor
    MyClass(int number) {
        this->number = number; // Using `this` to resolve naming conflict
    }
    MyClass& setValue(int x) {
        this->number = x;
        return *this;
    } // this will allow method chaining like: obj.setValue(10).display();
    // Display function using `this` pointer

    void display() {
    cout << "Object Number: " << this->number << endl;
    cout << "`this` Pointer Address: " << this << endl;
    }
};

int main() {
    MyClass obj1(100), obj2(200);
    obj1.display();
    obj2.display();
    obj2.setValue(10).display();
    return 0;
}

/*


*/