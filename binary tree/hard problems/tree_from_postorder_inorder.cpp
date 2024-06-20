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

TreeNode* makeTree(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, map<int, int>& hm) {
    if (ps > pe || is > ie) return NULL;

    TreeNode* root = new TreeNode(postorder[pe]);
    int inRoot = hm[postorder[pe]];
    int numsLeft = inRoot - is;

    root->left = makeTree(inorder, is, inRoot-1, postorder, ps, ps + numsLeft - 1, hm);
    root->right = makeTree(inorder, inRoot + 1, ie, postorder, ps + numsLeft, pe - 1, hm);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.size() != postorder.size()) return NULL;
    map<int, int> hm;
    for (int i = 0; i < inorder.size(); i++) {
        hm[inorder[i]] = i;
    }
    TreeNode* root = makeTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1, hm);
    return root;
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
    vector<int> postorder(n), inorder(n);
    for (int i = 0; i < n; i++) cin >> inorder[i];
    for (int i = 0; i < n; i++) cin >> postorder[i];
    TreeNode* newRoot = buildTree(inorder, postorder);
    cout << "New tree: ";
    printTree(newRoot);
    cout << endl;
    freeTree(newRoot);
    return 0;
}