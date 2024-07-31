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

    bool search(string word){
        Node* node = root;
        for(int i=0; i<word.length(); i++){
            if(!node->containKeys(word[i])){
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
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




void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    
    Trie trie;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int op;
        string word;
        cin >> op >> word;

        switch (op) {
            case 1:
                trie.insert(word);
                cout << "Inserted: " << word << endl;
                break;
            case 2:
                if (trie.search(word)) {
                    cout << word << " found in trie\n";
                } else {
                    cout << word << " not found in trie\n";
                }
                break;
            case 3:
                if (trie.startsWith(word)) {
                    cout << "Prefix " << word << " exists in trie\n";
                } else {
                    cout << "Prefix " << word << " does not exist in trie\n";
                }
                break;
            default:
                cout << "Invalid operation\n";
        }
    }

    return 0;
}