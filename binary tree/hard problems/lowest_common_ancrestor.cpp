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

TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == NULL || root == p || root == q){
        return root;
    }
    TreeNode* left = lca(root->left, p, q);
    TreeNode* right = lca(root->right, p, q);
    if(left == NULL){
        return right;
    }
    else if(right ==NULL){
        return left;
    }
    else{
        return root;
    }
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

TreeNode* find(TreeNode* root, int val) {
    if (!root || root->val == val) {
        return root;
    }
    TreeNode* left = find(root->left, val);
    if (left) {
        return left;
    }
    return find(root->right, val);
}

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main() {
    init_code();
    vector<string> nodes;
    string line;
    getline(cin, line);
    stringstream ss(line);
    string node;
    while (getline(ss, node, ' ')) {
        nodes.push_back(node);
    }
    TreeNode* root = buildTree(nodes);
    string p, q;
    cin >> p >> q;
    TreeNode* pNode = find(root, stoi(p));
    TreeNode* qNode = find(root, stoi(q));
    if (!pNode || !qNode) {
        cout << "One or both nodes not found in the tree." << endl;
    } else {
        TreeNode* lcaNode = lca(root, pNode, qNode);
        cout << lcaNode->val << endl;
    }
    freeTree(root);
    return 0;
}