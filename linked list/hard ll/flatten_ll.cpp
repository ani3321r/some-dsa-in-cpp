//the linked list is a bit complicated so no main function

#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* child;
    
    Node() {
        this->data = 0;
        next = NULL;
        child = NULL;
    }
    
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->child = NULL;
    }
    
    Node(int data, Node* next, Node* child) {
        this->data = data;
        this->next = next;
        this->child = child;
    }
};

Node* merge(Node* list1, Node* list2){
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            res->child = list1;
            res = list1;
            list1 = list1->child;
        }
        else{
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = nullptr;
    }
    if(list1) res->child = list1;
    else res->child = list2;
    if(dummyNode->child) dummyNode->child->next = nullptr;
    return dummyNode->child;
}

Node* flattenLL(Node*  head){
    if(head == NULL || head->next == NULL) return head;
    Node* mergedHead = flattenLL(head->next);
    head = merge(head, mergedHead);
    return head;
}