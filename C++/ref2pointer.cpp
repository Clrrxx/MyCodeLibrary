#include <iostream>
using namespace std;
void modifyPointer(int *p){     //need int *&ptr
    int x = 10;
    p = &x; //this is the local copy of pointer p, modifying here will not be reflected in the original call
}

int main(){
    int a = 5;
    int* ptr = &a;

    cout << "Before: " << *ptr <<endl;
    modifyPointer(ptr);
    cout << "After: " << *ptr <<endl;   //still remains as 5
    return 0;
}