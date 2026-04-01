#include "MyClass.h"
#include <iostream>
using namespace std;
int main(){
    MyClass toyClass1;
    toyClass1.doSomething();
    //cout<<toyClass1.data<<endl; (data is private inaccessible)
    MyClass toyClass1(20);
}
