#include <iostream>
#include <limits>
#include <cstring>
using namespace std;

int getValidInt(){
    int num;
    bool valid = false;
    while (!valid){
        if (cin.eof()) break;
        cin>>num;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter an integer: " <<endl;
        } else {
            cin.ignore(1000, '\n');
            valid = true;
        }
    }
    return num;
}
float getValidfloat(){
    float score = 0.00;
    bool valid = false;
    while(!valid){
        if (cin.eof()) break;
        cin>>score;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input! Please enter an float: " <<endl;
        } else {
            cin.ignore(1000, '\n');
            valid = true;
        }
    }
    return score;
}

int main(){
    char name[50];
    int studentID;
    float mathMark;
    
    while (true){
        cout<<"Enter the name: "<<std::endl;
        cin.getline(name, 50);

        if (strcmp(name, "#") == 0){
            break;
        }
        cout << "Enter ID: " <<std::endl;
        studentID = getValidInt();

        cout << "Enter mark: " <<std::endl;
        mathMark = getValidfloat();

        cout << "\nStudent Info\n";
        cout <<"Name: "<<name <<endl;
        cout <<"ID: "<<studentID<<endl;
        cout <<"Score: "<<mathMark <<endl;

    }
    cout<<"Program exited Successfully."<<endl;
    return 0;
}