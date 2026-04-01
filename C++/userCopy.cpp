#include <iostream>
class MyClass {
public:
    MyClass();
    MyClass(int a);
    // User-defined copy constructor
    MyClass(const MyClass &obj) {       //why use const -> we do not want to change the original object
        data = obj.data * 2;
        std::cout << "User-defined Copy constructor is called!" << std::endl;
}
    ~MyClass(){
    std::cout<<"Bye! "<<data <<std::endl;
}
    void doSomething();
private:
    int data;
};
MyClass::MyClass(){ data = 0; }
MyClass::MyClass(int a){
data = a;
}

void MyClass::doSomething() {
    std::cout << "Do something!"
<< std::endl;
}
int main() {
    MyClass toyClass1(10);
    MyClass toyClass2 = toyClass1;
}