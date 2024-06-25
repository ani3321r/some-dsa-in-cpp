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

class BSTIterator {
private:
    stack<TreeNode *> myStack;
    bool reverse = true;

    void pushAll(TreeNode *node) {
        while (node != NULL) {
            myStack.push(node);
            if (reverse) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
    }

public:
    BSTIterator(TreeNode *root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext() {
        return !myStack.empty();
    }

    int next() {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        if (!reverse) pushAll(tmpNode->right);
        else pushAll(tmpNode->left);
        return tmpNode->val;
    }
};

bool findTarget(TreeNode* root, int k) {
    if (!root) return false;
    BSTIterator l(root, false);
    BSTIterator r(root, true);
    int i = l.next();
    int j = r.next();
    while (i < j) {
        if (i + j == k) return true;
        else if (i + j < k) i = l.next();
        else j = r.next();
    }
    return false;
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
    int k;
    cin >> k;
    cout << (findTarget(root, k) ? "true" : "false");
    freeTree(root);
    return 0;
}