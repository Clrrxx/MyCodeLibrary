#include <iostream>
#include <vector>
using namespace std;

int main(){
    int input;
    vector <int> ivec;

    cout << "Enter 5: ";
    while (cin >> input)            //<- while loop stops when invalid input, not number
        ivec.push_back(input);      //use inbuilt function
    
    cout << "Array Contents: ";
    vector <int>::iterator it;
    for ( it = ivec.begin(); it!= ivec.end(); ++it){
        cout << *it <<" ";
    }
    cout <<endl;
    return 0;
}

/*
Use STL style algorithm .begin functions and .end function

*/