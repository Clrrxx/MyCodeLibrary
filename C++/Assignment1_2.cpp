#include <iostream>
#include <map>
#include <string>

using namespace std;

class PhoneBook{
private:
    map<string, string> contacts;

public:
    PhoneBook(){}
    void addContact(const string &name, const string &number){
        contacts[name] = number;
    }

    void removeContact(const string &name){
        contacts.erase(name);
    }

    void findContact(const string &name){
        map <string, string>::iterator search = contacts.find(name);
        if (search != contacts.end()){
            cout << search -> second <<endl;
        }else{
            cout <<"Not Found!\n";
        }

    }

    void displayAllContacts(){
        map <string,string>::iterator it;

        for (it = contacts.begin(); it!= contacts.end(); ++it){
            cout << it->first <<" -> "<<it->second << endl; 
        }
    }
};
