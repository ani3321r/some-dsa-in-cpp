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

TreeNode* makeTree(vector<int>& preorder, int& i, int bound) {
    if(i == preorder.size() || preorder[i] > bound) return NULL;
    TreeNode* root = new TreeNode(preorder[i++]);
    root->left = makeTree(preorder, i, root->val);
    root->right = makeTree(preorder, i, bound);
    return root;
}

TreeNode* buildTree(vector<int> &preorder){
    int i = 0;
    return makeTree(preorder, i, INT_MAX);
}

void freeTree(TreeNode* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
}

void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
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
    vector<int> preorder(n);
    for (int i = 0; i < n; i++) cin >> preorder[i];
    TreeNode* newRoot = buildTree(preorder);
    cout << "New tree: ";
    printTree(newRoot);
    cout << endl;
    freeTree(newRoot);
    return 0;
}