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

void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track) {
    queue<TreeNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
        TreeNode* current = queue.front();
        queue.pop();
        if (current->left) {
            parent_track[current->left] = current;
            queue.push(current->left);
        }
        if (current->right) {
            parent_track[current->right] = current;
            queue.push(current->right);
        }
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    unordered_map<TreeNode*, TreeNode*> parent_track;
    markParents(root, parent_track);
    unordered_map<TreeNode*, bool> visited;
    queue<TreeNode*> queue;
    queue.push(target);
    visited[target] = true;
    int curr_level = 0;
    while (!queue.empty()) {
        int size = queue.size();
        if (curr_level++ == k) break;
        for (int i = 0; i < size; i++) {
            TreeNode* current = queue.front();
            queue.pop();
            if (current->left && !visited[current->left]) {
                queue.push(current->left);
                visited[current->left] = true;
            }
            if (current->right && !visited[current->right]) {
                queue.push(current->right);
                visited[current->right] = true;
            }
            if (parent_track[current] && !visited[parent_track[current]]) {
                queue.push(parent_track[current]);
                visited[parent_track[current]] = true;
            }
        }
    }
    vector<int> result;
    while (!queue.empty()) {
        TreeNode* current = queue.front();
        queue.pop();
        result.push_back(current->val);
    }
    return result;
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
    int target_val;
    cin >> target_val;
    TreeNode* target = nullptr;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (curr->val == target_val) {
            target = curr;
            break;
        }
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
    if (!target) {
        cout << "Target node not found" << endl;
        freeTree(root);
        return 0;
    }
    int k;
    cin >> k;
    vector<int> result = distanceK(root, target, k);
    cout << "Nodes at distance " << k << " from target: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    freeTree(root);
    return 0;
}