#include <iostream>
#include <cmath>
using namespace std;
struct Node{
    double value;
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

void deleteNode(Node*& head, double number){
    Node *nodeptr, *prevNode;

    if (head == nullptr){return;}   //no node to remove, do nothing

    //if node is the first to remove
    if (fabs(head->value - number)<1e-9){
        nodeptr = head;                 //pointer = head (temp store the node to be deleted)
        head = head->next;              //head = head.next (head pointer gets assigned to the next node)
        delete nodeptr;                 //delete the node
        nodeptr = nullptr;              
    }else{
        nodeptr = head;

        //traverse the list to find the node
        while (nodeptr != nullptr and fabs(nodeptr->value -number)>1e-9){
            prevNode = nodeptr;         //prevNode = nodeptr
            nodeptr = nodeptr->next;    //nodeptr = nodeptr.next    keep traversing to find the node before the node to be deleted
        }

        if (nodeptr != nullptr){        //while node pointer is not None:
            prevNode->next = nodeptr->next;     //prev.next (node to be deleted) = nodepointer.next (node after node to be deleted)
            delete nodeptr;                     //delete the node
            nodeptr = nullptr;
        }
    }
}

void printlist(Node* head){
    Node* nodeptr = head;

    while (nodeptr){
        cout << nodeptr->value << "->";
        nodeptr = nodeptr->next;
    }
    cout<<"NULL"<<endl;
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
    insertNode2ListEnd(head, 12.5);
    insertNode2ListEnd(head, 13.5);
    cout << "1st Node: "<<head->value<<endl;            //head.val
    cout << "2nd Node: "<<head->next->value<<endl;      //head.next.val
    printlist(head);
    deleteNode(head, 13.5);
    printlist(head);
    destroylist(head);
    printlist(head);
    return 0;
}