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

Node *addTwoNum(Node *num1, Node *num2){
    Node* dummyHead = new Node(-1);
    Node* curr = dummyHead;
    Node* temp1 = num1;
    Node* temp2 = num2;
    int carry = 0;
    while(temp1 != NULL || temp2 != NULL || carry){
        int sum = carry;
        if(temp1) {
            sum += temp1->data;
            temp1 = temp1->next;
        }
        if(temp2) {
            sum += temp2->data;
            temp2 = temp2->next;
        }
        Node* newNode = new Node(sum % 10);
        carry = sum / 10;
        curr->next = newNode;
        curr = curr->next;
    }
    return dummyHead->next;
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
    vector<int> ll1(n), ll2(n);
    for(int i=0; i<n; i++) cin >> ll1[i];
    for(int i=0; i<n; i++) cin >> ll2[i];
    Node* head1 = convertArr2LL(ll1);
    Node* head2 = convertArr2LL(ll2);
    Node* ans = addTwoNum(head1, head2);
    while(ans){
        cout << ans->data << " ";
        ans = ans->next;
    }
    return 0;
}