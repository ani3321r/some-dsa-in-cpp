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

vector<int> getInorder(TreeNode* root){
    vector<int> inorder;
    TreeNode *cur = root;
    while(cur != NULL){
        if(cur->left == NULL){
            inorder.push_back(cur->val);
            cur = cur->right;
        }
        else{
            TreeNode *prev = cur->left;
            while(prev->right && prev->right != cur){
                prev = prev->right;
            }
            if(prev->right == NULL){
                prev->right = cur;
                cur = cur->left;
            }
            else{
                prev->right = NULL;
                inorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return inorder;
}

TreeNode* buildTree(vector<string>& nodes) {
    if (nodes.empty()) return nullptr;
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(stoi(nodes[0]));
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
    #endif
}

int main() {
    init_code();
    vector<string> nodes;
    string line;
    getline(cin, line);
    istringstream iss(line);
    string node;
    while (iss >> node) {
        nodes.push_back(node);
    }
    TreeNode* root = buildTree(nodes);
    vector<int> ans = getInorder(root);
    for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
    freeTree(root);
    return 0;
}