#include <iostream>
class MyClass {
public:
    int* data; // Pointer to dynamically allocated memory
    // Constructor
    MyClass(int val) {
        data = new int(val); // Allocating memory
        std::cout << "Constructor called, allocating memory at " << data <<std::endl;
        }
        //No user-defined copy constructor here
        // Destructor -> used to free dynamically allocated memory, avoiding mem leakage
        ~MyClass() {
        std::cout << "Destructor called, freeing memory at " << data <<std::endl;
        delete data; // Deallocating memory
    }
};
int main() {
    MyClass obj1(10); // Constructor called

    MyClass obj2 = obj1; // Default copy constructor called – Shallow Copy!!!


    // Modifying obj2 will also affect obj1 due to shared memory
    *obj2.data = 20;


    std::cout << "obj1.data: " << *obj1.data << std::endl;
    std::cout << "obj2.data: " << *obj2.data << std::endl;


    return 0; // Destructor called twice, leading to double deletion (ERROR!)
}

//default copy constructor can only perform shallow copy -> obj created by simply copying the data, only meme address is copied
//both will be referencing the same thing