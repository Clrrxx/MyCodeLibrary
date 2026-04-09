#include <iostream>
using namespace std;

//function hiding

class Base{
public:
    void display(int v = 10){
        cout<<v<<endl;;
    }
};

class derived : public Base{
public:
    void display(int a = 100){
        cout << a<<endl;;
    }
};
/*
int main(){
    Base b;
    derived a;
    b.display();
    a.display();
}
*/

/*
think of it as layering the display function inherited from base over with the same
display method in the derived class

since both are effectively the same, compiler will just take the one in the derived class

redefining the base class mtds
but this will case static binding, where function calls are bound at the compile time
*/
int main(){
    derived d;
    d.display();    //derived called

    Base* ptr = &d;
    ptr ->display();    //base called
    return 0;   

    // static binding causes the base class display to be called
}
