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

Node *oddEven(Node *head){
    if(head == NULL || head->next == NULL) return head;
    Node* odd = head;
    Node* even = head->next;
    Node* temp = even;
    while(even !=  NULL && even->next != NULL){
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = temp;
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
    vector<int> ll(n);
    for(int i=0; i<n; i++) cin >> ll[i];
    Node* head = convertArr2LL(ll);
    Node* ans = oddEven(head);
    while(ans){
        cout << ans->data << " ";
        ans = ans->next;
    }
    return 0;
}