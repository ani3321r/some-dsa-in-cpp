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

string serialize(TreeNode* root) {
    if (!root) return "#";
    string s = to_string(root->val) + ",";
    s += serialize(root->left) + ",";
    s += serialize(root->right);
    return s;
}

TreeNode* deserializeHelper(istringstream& iss) {
    string val;
    getline(iss, val, ',');
    if (val == "#") return nullptr;
    TreeNode* node = new TreeNode(stoi(val));
    node->left = deserializeHelper(iss);
    node->right = deserializeHelper(iss);
    return node;
}

TreeNode* deserialize(string data) {
    istringstream iss(data);
    return deserializeHelper(iss);
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

void printTree(TreeNode* root) {
    if (root == nullptr) {
        cout << "null ";
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
    string s = serialize(root);
    cout << "Serialized: " << s << endl;
    TreeNode* newRoot = deserialize(s);
    cout << "Deserialized: ";
    printTree(newRoot);
    cout << endl;
    freeTree(root);
    freeTree(newRoot);
    return 0;
}