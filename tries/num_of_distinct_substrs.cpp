#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    Node *links[26];
    bool flag = false;
    bool containKeys(char ch){
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node* node){
        links[ch - 'a'] = node;
    }
    Node* get(char ch){
        return links[ch - 'a'];
    }    
};

int distinctSubStr(string a){
    int cnt = 0;
    Node* root = new Node();
    for(int i=0; i<a.size(); i++){
        Node* node = root;
        for(int j=i; j<a.size(); j++){
            if(!node->containKeys(a[j])){
                cnt++;
                node->put(a[j], new Node());
            }
            node = node->get(a[j]);
        }
    }
    return cnt + 1;
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    string s;
    cin >> s;
    int ans = distinctSubStr(s);
    cout << ans << endl;

    return 0;
}