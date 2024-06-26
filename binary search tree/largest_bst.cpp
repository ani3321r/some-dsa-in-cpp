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

class NodeValue {
public: 
    int maxNode, minNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize){
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }    
};

class Solution{
private: 
    NodeValue largestBstHelper(TreeNode* root){
        if(!root){
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        auto left = largestBstHelper(root->left);
        auto right = largestBstHelper(root->right);
        if(left.maxNode < root->val && root->val < right.minNode){
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), left.maxSize + right.maxSize + 1);
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }    
public: 
    int largestBST(TreeNode* root){
        return largestBstHelper(root).maxSize;
    }    
};

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

void printTree(TreeNode* root) {
    if (root == nullptr) return;
    
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
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
    Solution ans;
    cout << ans.largestBST(root);
    freeTree(root);
    return 0;
}