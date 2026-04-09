#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int input;
    vector <int> ivec;

    cout << "Enter 5: ";
    while (cin >> input)       
        ivec.push_back(input);


    sort(ivec.begin(), ivec.end());     //sort takes (interator begin, iterator end)


    cout << "Array Contents: ";
    vector <int>::iterator it;
    for ( it = ivec.begin(); it!= ivec.end(); ++it){
        cout << *it <<" ";
    }
}