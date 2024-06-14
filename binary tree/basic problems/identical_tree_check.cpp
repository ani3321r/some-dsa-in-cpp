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

bool isSameTree(TreeNode *p, TreeNode *q){
    if(p == NULL || q == NULL){
        return p == q;
    }
    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
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
    string input1, input2;
    getline(cin, input1);
    getline(cin, input2);
    stringstream ss1(input1), ss2(input2);
    string node;
    vector<string> nodes1, nodes2;
    while (getline(ss1, node, ' ')) {
        nodes1.push_back(node);
    }
    while (getline(ss2, node, ' ')) {
        nodes2.push_back(node);
    }
    TreeNode* root1 = buildTree(nodes1);
    TreeNode* root2 = buildTree(nodes2);
    bool result = isSameTree(root1, root2);
    cout << (result ? "true" : "false");
    freeTree(root1);
    freeTree(root2);
    return 0;
}