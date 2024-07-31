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
    void setEnd(){
        flag = true;
    }
    bool isEnd(){
        return flag;
    }
};

class Trie{
private: Node* root;

public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node-> containKeys(word[i])){
                node-> put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool startsWith(string prefix){
        Node* node = root;
        for(int i=0; i<prefix.length(); i++){
            if(!node->containKeys(prefix[i])){
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};

string completeString(int n, vector<string> &a){
    Trie trie;
    for(auto &it : a){
        trie.insert(it);
    }
    string longest = "";
    for(auto &it : a){
        if(trie.startsWith(it)){
            if(it.length()>longest.length()){
                longest = it;
            }
            else if(it.length() == longest.length() && it < longest){
                longest = it;
            }
        }
    }
    if(longest == "") return "None";
    return longest;
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
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    string ans = completeString(n, words);
    cout << ans << endl;

    return 0;
}