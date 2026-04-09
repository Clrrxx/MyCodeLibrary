#include <iostream>
#include <list>
using namespace std;

int main(){
    list <int> mylist;

    list <int>::iterator iter;

    for (int x = 0; x<100; x += 10)
        mylist.push_back(x);

    for (iter = mylist.begin(); iter!= mylist.end(); iter ++)
    cout << *iter <<" ";
    cout <<endl;

    //reverse the list
    mylist.reverse();

    for (iter = mylist.begin(); iter!= mylist.end(); iter ++)
    cout << *iter <<" ";
    cout <<endl;
    return 0;

}


/*
List is much quicker than vectors to insert items at the front and the back of the list
*/