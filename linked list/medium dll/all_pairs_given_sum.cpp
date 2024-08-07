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

Node* findTail(Node *head){
    Node* tail = head;
    while(tail->next != NULL) tail = tail->next;
    return tail;
}

vector<pair<int, int>> findPairs(Node* head, int k){
    vector<pair<int, int>> ans;
    if(head == NULL) return ans;
    Node* left = head;
    Node* right = findTail(head);
    while(left->data < right->data){
        if(left->data + right->data == k){
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if(left->data + right->data < k){
            left = left->next;
        }
        else right = right->prev;
    }
    return ans;
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
    vector<int> ll1(n);
    for(int i=0; i<n; i++) cin >> ll1[i];
    Node* head1 = convertArr2DLL(ll1);
    vector<pair<int, int>> ans = findPairs(head1, k);
    for(int i=0; i<ans.size(); i++) cout << ans[i].first << "," << ans[i].second << endl;
    return 0;
}