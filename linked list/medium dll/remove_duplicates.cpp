#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    
    Node() {
        this->data = 0;
        next = NULL;
        prev = NULL;
    }
    
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    
    Node(int data, Node* next, Node* prev) {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

Node* convertArr2DLL(vector<int>& arr) {
    if (arr.empty()) return NULL;

    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
        mover = temp;
    }

    return head;
}

Node *removeDuplicates(Node *head){
    Node* temp = head;
    while(temp != NULL && temp->next != NULL){
        Node* nextNode = temp->next;
        while(nextNode != NULL && nextNode->data == temp->data){
            Node* duplicate = nextNode;
            nextNode = nextNode->next;
            free(duplicate);
        }
        temp->next = nextNode;
        if(nextNode != NULL) nextNode->prev = temp;

        temp = temp->next;
    }
    return head;
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
    vector<int> ll1(n);
    for(int i=0; i<n; i++) cin >> ll1[i];
    Node* head1 = convertArr2DLL(ll1);
    Node* ans = removeDuplicates(head1);
    while(ans){
        cout << ans->data << " ";
        ans = ans->next;
    }
    return 0;
}