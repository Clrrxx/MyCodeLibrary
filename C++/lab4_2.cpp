#include <iostream>
#include <string>
using namespace std;

class Sports{
protected:
    string sport;
public:
    Sports(string sport) :sport(sport){
        cout << "Sports Constructed" <<endl;
    }
    ~Sports(){cout<<"Sports destroyed" <<endl;}

    void displaySports() const {
        cout << "Sport: " <<sport <<endl;
    }
};

class Academics{
protected:
    float gpa;
public:
    Academics(float gpa) : gpa(gpa){
        cout << "Academics Constructed" <<endl;
    }
    ~Academics(){cout << "Academics Destroyed" <<endl;}

    void displayAcademics() const{
        cout << "GPA: " << gpa <<endl;
    }
};

class StudentAthlete : public Sports, public Academics{
private:
    string name;
    int age;
    int studentID;
public:
    StudentAthlete(string sports, float gpa, string name, int age, int studentID);
    ~StudentAthlete(){cout << "StudentAthlete Destroyed" <<endl;}

    void displayInfo() const{
        cout << "Name: " <<name <<", Age: "<<age<<", Student ID" <<studentID<<endl;
        Sports::displaySports();
        Academics::displayAcademics();
    }
};

StudentAthlete::StudentAthlete(string sports, float gpa, string name, int age, int studentID):Sports(sports), Academics(gpa), name(name), age(age), studentID(studentID){
        cout << "StudentAthlete Constructed" <<endl;
    }

int main(){
    cout << "Enter: NAME, AGE, STUDENTID, SPORTS AND GPA: "<<endl;

    string name, sports;
    int age, studentID;
    float gpa;

    cin >> name >> age >> studentID >> sports >> gpa;

    StudentAthlete stu(sports, gpa, name, age, studentID);

    cout <<endl;
    stu.displayInfo();
    cout <<endl;

    //test for inheritance
    stu.displaySports();
    stu.displayAcademics();
    
    cout << endl;

}