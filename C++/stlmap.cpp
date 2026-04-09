#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    
    map<string, int> studentGrades;

    studentGrades["Alice"] = 90;
    studentGrades["Bob"] = 80;
    studentGrades["Charlie"] = 75;
    studentGrades["David"] = 99;

    //display all students
    cout << "Student Grades: \n";
    map<string, int>::iterator it;
    for (it = studentGrades.begin(); it!= studentGrades.end(); ++it){
        cout << it->first << " -> " << it->second <<endl;
    }

    //search for student
    string name = "Charlie";
    map<string, int>::iterator search = studentGrades.find(name);
    if (search != studentGrades.end()){
        cout << "\n" <<name <<"'s Grade: " <<search -> second << endl;
    }else{
        cout <<"\nStudent not found." <<endl;
    }

    //delete student
    studentGrades.erase("Bob");

    //display updated map
    cout << "new\n";
    for (it = studentGrades.begin(); it!= studentGrades.end(); ++it){
        cout << it->first << " -> " << it->second <<endl;
    }
    return 0;
}