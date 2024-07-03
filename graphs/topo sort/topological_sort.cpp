#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& vis, stack<int>& st, vector<int> adj[]) {
    vis[node] = 1;
    for(auto it: adj[node]) {
        if(!vis[it]) dfs(it, vis, st, adj);
    }
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    stack<int> st;
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }
    vector<int> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    int V, E;
    cin >> V >> E;
    vector<int> adj[V];
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    vector<int> ans = topoSort(V, adj);
    for(int i : ans) cout << i << " ";
    cout << endl;
    return 0;
}