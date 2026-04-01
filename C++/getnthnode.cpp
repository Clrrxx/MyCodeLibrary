#include <iostream>
#include <cmath>
using namespace std;
struct Node{
    int value;
    Node* next;
};

void insertNode2ListEnd(Node*& head, double newVal){
    Node* newNode = new Node;
    newNode->value = newVal;
    newNode->next = nullptr;    //put newNode as the last node 

    if (head == nullptr){   //if list is empty, head = newNode
        head = newNode;
    }else{              //list is not empty, traverse the list, find the end, then insert at the end
        Node* temp = head;
        while (temp->next != nullptr){      //while temp.next is not None:
            temp = temp->next;              //temp = temp.next
        }
        temp->next = newNode;               //temp.next = newNode (newNode is at the last node before the null pointer)
    }
}

int getnthNode(const Node*head, int n){
    const Node* curr = head;
    int count = 1;

    while (curr!=nullptr){
        if (count == n){
            return curr->value;
        }
        curr = curr->next;
        count++;
    }
    return -1;
}

void destroylist(Node*& head){
    Node *nodeptr = head;
    Node *garbage = nullptr;
    while (nodeptr){
        //garbage keeps track of the popped node
        garbage = nodeptr;

        //move to next node
        nodeptr = nodeptr->next;

        //delete the node
        delete garbage;
        garbage = nullptr;
    }
    head = nullptr;
}

int main(){
    Node* head = nullptr;
    int size;
    cout << "Enter size: "<<endl;
    cin >> size;
    cout <<"Enter elements: "<<endl;

    for(int i = 0; i<size; i++){
        int value;
        cin >>value;
        insertNode2ListEnd(head, value);
    }

    while (true){
        cout <<"Enter n: "<<endl;
        int n;
        cin >>n;
        if (n == -1) break;
        cout << getnthNode(head, n) <<endl;
    }
    destroylist(head);
    return 0;
}