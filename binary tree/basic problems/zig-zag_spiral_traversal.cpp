#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzag(TreeNode* root){
    vector<vector<int>> ans;
    if(root == NULL){
        return ans;
    }
    queue<TreeNode*> nodesQueue;
    nodesQueue.push(root);
    bool leToRe = true;
    while(!nodesQueue.empty()){
        int size = nodesQueue.size();
        vector<int> row(size);
        for(int i=0; i<size; i++){
            TreeNode* node = nodesQueue.front();
            nodesQueue.pop();
            int index = (leToRe) ? i:(size - 1 - i);
            row[index] = node->val;
            if(node->left){
                nodesQueue.push(node->left);
            }
            if(node->right){
                nodesQueue.push(node->right);
            }
        }
        leToRe = !leToRe;
        ans.push_back(row);
    }
    return ans;
}

TreeNode* buildTree(vector<string>& nodes) {
    if (nodes.empty()) return NULL;
    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* node = q.front();
        q.pop();
        if (i < nodes.size() && nodes[i] != "null") {
            node->left = new TreeNode(stoi(nodes[i]));
            q.push(node->left);
        }
        i++;
        if (i < nodes.size() && nodes[i] != "null") {
            node->right = new TreeNode(stoi(nodes[i]));
            q.push(node->right);
        }
        i++;
    }
    return root;
}

void freeTree(TreeNode* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
}

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main() {
    init_code();
    string input;
    getline(cin, input);
    stringstream ss(input);
    string node;
    vector<string> nodes;
    while (getline(ss, node, ' ')) {
        nodes.push_back(node);
    }
    TreeNode* root = buildTree(nodes);
    vector<vector<int>> ans = zigzag(root);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    freeTree(root);
    return 0;
}