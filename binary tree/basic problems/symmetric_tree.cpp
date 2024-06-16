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

bool isSym(TreeNode* root1, TreeNode* root2){
    if(root1 == NULL || root2 == NULL){
        return root1 == root2;
    }
    return (root1->val == root2->val) && isSym(root1->left, root2->right) && isSym(root1->right, root2->left);
}

bool isSymmetric(TreeNode* root){
    if(!root) return true;
    return isSym(root->left, root->right);
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
    cout << isSymmetric(root);
    freeTree(root);
    return 0;
}