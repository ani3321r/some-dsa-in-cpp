#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    Node *links[2];
    bool containKeys(int bit) {
        return (links[bit] != NULL);
    }
    void put(int bit, Node* node) {
        links[bit] = node;
    }
    Node* get(int bit) {
        return links[bit];
    }    
};

class Trie {
private: 
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(!node->containKeys(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num) {
        Node* node = root;
        int maxNum = 0;
        for(int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if(node->containKeys(1-bit)) {
                maxNum = maxNum | (1 << i);
                node = node->get(1-bit);
            } 
            else {
                node = node->get(bit);
            }
        }    
        return maxNum;
    }
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries) {
    sort(arr.begin(), arr.end());
    vector<pair<int, pair<int, int>>> oQ;
    int q = queries.size();
    for(int i = 0; i < q; i++) {
        oQ.push_back({queries[i][1], {queries[i][0], i}});
    }
    sort(oQ.begin(), oQ.end());
    vector<int> ans(q, 0);
    int ind = 0;
    int n = arr.size();
    Trie trie;
    for(int i = 0; i < q; i++) {
        int ai = oQ[i].first;
        int xi = oQ[i].second.first;
        int qInd = oQ[i].second.second;
        while(ind < n && arr[ind] <= ai) {
            trie.insert(arr[ind]);
            ind++;
        }
        if(ind == 0) ans[qInd] = -1;
        else ans[qInd] = trie.getMax(xi);
    }
    return ans;
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    int n, m;
    cin >> n >> m;  
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    vector<vector<int>> queries(m, vector<int>(2));
    for(int i = 0; i < m; i++) {
        cin >> queries[i][0] >> queries[i][1];
    }
    
    vector<int> ans = maxXorQueries(arr, queries);
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}