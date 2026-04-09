#include <iostream>
#include <string>
using namespace std;

struct StringNode{
    string name;
    StringNode* next;
};

void printlist(const StringNode* head){
    const StringNode* temp = head;
    while(temp){
        cout << temp->name << "->";
        temp = temp->next;
    }
    cout << "NULL" <<endl;
}

void append(StringNode*& head, const string& name){
    StringNode* newNode = new StringNode;
    newNode->name = name;
    newNode->next = nullptr;

    if (head == nullptr){
        head = newNode;
        return;
    }
    StringNode* temp = head;
    while (temp->next){
        temp = temp->next;
    }
    temp->next = newNode;
}

void freeList(StringNode*& head){
    while (head){
        StringNode* temp = head;
        head = head->next;
        delete temp;
    }
}

void removeDuplicates(StringNode*& head){
    StringNode* curr = head, *temp;
    while (curr){
        temp = curr;
        
        while (temp->next){
            if (temp->next->name == curr->name){
                temp->next = temp->next->next;
            }else{
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
}

int main(){
    StringNode* head = nullptr;

    cout << "1) Append Node" <<endl;
    cout << "2) PrintList" <<endl;
    cout << "3) Remove Duplicates" <<endl;
    cout << "4) Exit" <<endl;

    int cmd;
    do {
        cout << "Enter: "<<endl;
        cin >> cmd;

        switch (cmd){
            case 1:{
                string name;
                cin >> name;
                append(head, name);
                break;
            }

            case 2:{
                printlist(head);
                break;
            }

            case 3:{
                removeDuplicates(head);
                break;
            }

            case 4:{
                break;
            }

            default:
                cout <<"Unknown cmd" <<endl;
            
        }
    }while (cmd != 4);

    freeList(head);
    return 0;
}