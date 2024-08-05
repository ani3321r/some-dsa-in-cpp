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

Node *findIntersection(Node *firstHead, Node *secondHead){
    if(firstHead == NULL || secondHead->next == NULL) return NULL;
    Node* temp1 = firstHead;;
    Node* temp2 = secondHead;
    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;

        if(temp1 == temp2) return temp1;
        if(temp1 == NULL) temp1 = secondHead;
        if(temp2 == NULL) temp2 = firstHead;
    }
    return temp1;
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    int n, m, k;
    cin >> n >> m >> k;
    k = k - 1; 
    vector<int> ll1(n);
    vector<int> ll2(m);

    for(int i = 0; i < n; i++) cin >> ll1[i];
    for(int i = 0; i < m; i++) cin >> ll2[i];

    Node* head1 = convertArr2LL(ll1);
    Node* head2 = convertArr2LL(ll2);

    if (k < n && k < m) {
        Node* temp1 = head1;
        Node* temp2 = head2;
        for(int i = 0; i < k; i++) {
            temp1 = temp1->next;
        }
        while(temp2->next != NULL) {
            temp2 = temp2->next;
        }
        temp2->next = temp1;
    }

    Node* ans = findIntersection(head1, head2);
    if(ans != NULL)
        cout << ans->data << endl;
    else
        cout << "No intersection found" << endl;

    return 0;
}