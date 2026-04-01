#include <iostream>
using namespace std;
class MyClass {
private:
    int value;

public:
    MyClass(int v) {value = v; }
    
    // Overloading the + operator
    MyClass operator+(const MyClass& obj) const {
        int sum = value + obj.value;
        return MyClass(sum);
    }
    
    // Declaring friend function to overload << operator
    friend ostream& operator<<(ostream& out, const MyClass& obj);
    };

    //if never declare friend, cannot print out member values

    // Overloading the << operator for output
    ostream& operator<<(ostream& out, const MyClass& obj) {
        out << "value: " << obj.value;
        return out;
}
int main() {
    MyClass obj1(10), obj2(20);
    MyClass obj3 = obj1 + obj2; // Using overloaded + operator
    cout << obj3 << endl;
    return 0;
}