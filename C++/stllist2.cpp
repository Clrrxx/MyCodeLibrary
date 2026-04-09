#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void printElem(int x){
    cout << x << " ";
}

int main(){
    list <int> mylist;


    for (int x = 0; x<100; x += 10)
        mylist.push_back(x);

    cout <<"List Elements: ";
    for_each(mylist.begin(), mylist.end(), printElem);
    cout <<endl;
    return 0;
}