#include <iostream>
using namespace std;
union Result {
    int mark;
    char grade; // Can be only 'A', 'B' or 'C'
};
struct Student {
    char studentName[50];
    bool isGrade;
    int finalMark; // Used to store the final mark
    Result res;
    void convertGrade() {
    // To-do: WRITE YOUR CODE HERE
        if (isGrade){
            if (res.grade == 'A') finalMark = 90;
            else if (res.grade == 'B') finalMark = 80;
            else finalMark = 60;
        }else{
            res.mark = finalMark;
        }
    }
};
void displayStudentInfo(Student *students, int count){
    float sum = 0.0;
    float average = 0.0;
    cout << "\nStudent Result: "<<endl;
    for (int i =0; i<count; i++){
        cout<<"Name: "<<students[i].studentName<<", Final mark: "<<students[i].finalMark<<endl;
        sum += (float) students[i].finalMark;
    }
    cout<<endl;
    average = sum / (float) count;
    cout <<"Average Final Mark: "<<average;

}

int main() {
// To-do: WRITE YOUR CODE HERE
    int size;

    cout<<"How many students do you want to input?"<<endl;
    cout<<"Enter the student size: ";
    cin >> size;
    cin.ignore();

    Student*arr = new Student[size];

    for (int i = 0; i<size; i++){
        char choice;
        cout<<"Enter student name: ";
        cin.getline(arr[i].studentName, 50);

        cout<<"Enter 'G' if it is a grade or 'M' if result is mark: ";
        cin >> choice;
        cin.ignore();
        if (choice == 'M'){
            cout <<"Enter mark (0-100): ";
            cin >> arr[i].finalMark;
            cin.ignore();
        }else if (choice == 'G'){
            //assign isgrade true
            arr[i].isGrade = (choice == 'G');
            
            cout <<"Enter grade (A,B,C): ";
            cin>>arr[i].res.grade;
            cin.ignore();
            switch(arr[i].res.grade){
                case 'A': arr[i].convertGrade();
                        break;
                case 'B': arr[i].convertGrade();
                        break;
                case 'C': arr[i].convertGrade();
                        break;
                default: cout << "Invalid grade" << endl;
            }
        }
    }
    displayStudentInfo(arr, size);

return 0;
}
