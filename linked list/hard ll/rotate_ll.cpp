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

Node* findNthNode(Node* temp, int k){
    int cnt = 1;
    while(temp != NULL){
        if(cnt == k) return temp;
        cnt++;
        temp = temp->next;
    }
    return temp;
}

Node *rotate(Node *head, int k){
    if(head == NULL || k==0) return head;
    Node* tail = head;
    int len = 1;
    while(tail->next != NULL){
        tail = tail->next;
        len += 1;
    }

    if(k % len == 0) return head;
    k = k%len;
    tail->next = head;
    Node* newLastNode = findNthNode(head, len-k);

    head = newLastNode->next;
    newLastNode->next = NULL;

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
    int n, k;
    cin >> n >> k;
    vector<int> ll(n);
    for(int i=0; i<n; i++) cin >> ll[i];
    Node* head = convertArr2LL(ll);
    Node* ans = rotate(head, k);
    while(ans){
        cout << ans->data << " ";
        ans = ans->next;
    }
    return 0;
}