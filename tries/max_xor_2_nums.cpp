#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    Node *links[2];
    bool containKeys(int bit){
        return (links[bit] != NULL);
    }
    void put(int bit, Node* node){
        links[bit] = node;
    }
    Node* get(int bit){
        return links[bit];
    }    
};

class Trie{
private: Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insert(int num){
        Node* node = root;
        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(!node-> containKeys(bit)){
                node-> put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num){
        Node* node = root;
        int maxNum = 0;
        for(int i=31; i>=0; i--){
            int bit = (num >> i) & 1;
            if(node->containKeys(1-bit)){
                maxNum = maxNum | (1<<i);
                node = node->get(1-bit);
            } 
            else{
                node = node->get(bit);
            }
        }    
        return maxNum;
    }
};

int maxXor(int n, vector<int> &arr){
    Trie trie;
    for(auto &it: arr) trie.insert(it);
    int maxi = 0;
    for(auto &it: arr){
        maxi = max(maxi, trie.getMax(it));
    }
    return maxi;
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    int n;
    cin >> n;  
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    int ans = maxXor(n, arr);
    cout << ans << endl;
    return 0;
}