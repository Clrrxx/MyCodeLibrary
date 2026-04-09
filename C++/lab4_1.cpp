#include <iostream>
#include <list>
#include <string>
using namespace std;

class PatientQueue{
private:
    std::list<std::string> queue;
public:
    PatientQueue() : queue(){}
    ~PatientQueue(){}

    void addPatient(const string &name){
        queue.push_back(name);
    }

    string servePatient(){
        string ans;
        if (isEmpty()){
            return "Queue Empty";
        }else{
            ans = queue.front();
            queue.pop_front();
            return ans;
        }
    }

    bool isEmpty(){
        return queue.empty();
    }

    void display(){
        list<string>::iterator it;
        for (it = queue.begin(); it != queue.end(); it++){
            cout << *it << " ";
        }
        cout << endl;
    }
};

int main(){
    PatientQueue clinicQueue;

    cout << "1) Add patient" <<endl;
    cout << "2) Display Queue" <<endl;
    cout << "3) Check Queue" <<endl;
    cout << "4) Serve Patient" <<endl;
    cout << "5) Exit" <<endl;

    int cmd;
    do{
        cout << "Enter Command: " << endl;
        cin >>cmd;
        switch (cmd){
            case 1: {
                string value;
                cin >> value;
                clinicQueue.addPatient(value);
            }
            break;
            case 2:{
                clinicQueue.display();
                break;
            }
            case 3:{
                if (clinicQueue.isEmpty()){
                    cout << "Queue currently empty" <<endl;
                }else{
                    cout <<"Wait your turn" <<endl;
                }
                break;
            }
            case 4:{
                cout <<"Serving patient: " <<clinicQueue.servePatient() <<endl;
                break;
            }
            case 5:
                break;
            default:
                cout << "Unknown\n";
        }
    }while (cmd != 5);
    return 0;
}