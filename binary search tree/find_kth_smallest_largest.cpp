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

TreeNode* findLastRight(TreeNode* root){
    if(root->right == NULL) return root;
    return findLastRight(root->right);
}

TreeNode* helper(TreeNode* root){
    if(root->left == NULL) return root->right;
    if(root->right == NULL) return root->left;
    TreeNode* rightChild = root->right;
    TreeNode* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;
    return root->left;
}

void reverseInorder(TreeNode* node, int& counter, int k, int& kLargest){
    if(!node || counter >= k) return;
    reverseInorder(node->right, counter, k, kLargest);
    counter++;
    if(counter == k){
        kLargest = node->val;
        return;
    }
    reverseInorder(node->left, counter, k, kLargest);
}

void inorder(TreeNode* node, int& counter, int k, int& kLargest){
    if(!node || counter >= k) return;
    inorder(node->left, counter, k, kLargest);
    counter++;
    if(counter == k){
        kLargest = node->val;
        return;
    }
    inorder(node->right, counter, k, kLargest);
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

pair<int, int> findKth(TreeNode* root, int k){
    int kSmallest = INT_MIN, kLargest = INT_MIN;
    int counter = 0;
    inorder(root, counter, k, kSmallest);
    counter = 0;
    reverseInorder(root, counter, k, kLargest);
    return make_pair(kSmallest, kLargest);
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
    int k;
    cin >> k;
    auto ans = findKth(root, k);
    cout << "smallest: " << ans.first << " largest: " << ans.second;
    freeTree(root);
    return 0;
}