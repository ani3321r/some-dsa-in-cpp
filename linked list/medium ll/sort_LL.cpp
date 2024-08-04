#include <iostream>
#include <vector>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(){
            this->data = 0;
            next = NULL;
        }
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
        Node(int data, Node* next){
            this->data = data;
            this->next = next;
        }
};

Node *convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node *findMiddle(Node *head){
    Node* slow = head;
    Node* fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* mergeLists(Node* list1, Node* list2){
    Node* duNode = new Node(-1);
    Node* temp = duNode;
    while(list1 != NULL && list2 != NULL){
        if(list1->data < list2->data){
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }
    if(list1) temp->next = list1;
    else temp->next = list2;

    return duNode->next;
}

Node *sortLL(Node *head){
    if(head == NULL || head->next == NULL) return head;
    Node* middle = findMiddle(head);
    Node* right = middle->next;
    middle->next = nullptr;
    Node* left = head;

    left = sortLL(left);
    right = sortLL(right);
    return mergeLists(left, right);
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main(){
    init_code();
    int n;
    cin >> n;
    vector<int> ll(n);
    for(int i=0; i<n; i++) cin >> ll[i];
    Node* head = convertArr2LL(ll);
    Node* ans = sortLL(head);
    while(ans){
        cout << ans->data << " ";
        ans = ans->next;
    }
    return 0;
}