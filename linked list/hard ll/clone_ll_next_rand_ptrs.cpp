//the linked list is a bit complicated so no main function

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* random;
    
    Node() {
        this->data = 0;
        next = NULL;
        random = NULL;
    }
    
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
    
    Node(int data, Node* next, Node* random) {
        this->data = data;
        this->next = next;
        this->random = random;
    }
};

void insertCopyBt(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* nextElement = temp->next;
        Node* copy = new Node(temp->data);
        copy->next = nextElement;
        temp->next = copy;
        temp = nextElement;
    }
}

void connectRandPtrs(Node* head){
    Node* temp = head;
    while(temp != NULL){
        Node* copyNode = temp->next;
        if(temp->random){
            copyNode->random = temp->random->next;
        }
        else{
            copyNode->random = nullptr;
        }
        temp = temp->next->next;
    }
}

Node* getDeepCopyList(Node* head){
    Node* temp = head;
    Node* dummmyNode = new Node(-1);
    Node* res = dummmyNode;
    while(temp != NULL){
        res->next = temp->next;
        res = res->next;
        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummmyNode->next;
}

Node *cloneLL(Node *head){
    insertCopyBt(head);
    connectRandPtrs(head);
    return getDeepCopyList(head);
}