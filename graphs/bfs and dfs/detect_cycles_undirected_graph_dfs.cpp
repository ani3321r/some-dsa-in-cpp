#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int parent, vector<int>& vis, vector<int> adj[]) {
    vis[node] = 1;
    for(auto adjacentNode : adj[node]) {
        if(!vis[adjacentNode]) {
            if(dfs(adjacentNode, node, vis, adj) == true) {
                return true;
            }
        } else if(adjacentNode != parent) return true;
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    for(int i = 0; i < V; i++) {
        if(!vis[i]) {
            if(dfs(i, -1, vis, adj) == true) return true;
        }
    }
    return false;
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
        adj[v].push_back(u);
    }
    if(isCycle(V, adj))
        cout << "Graph contains cycle\n";
    else
        cout << "Graph doesn't contain cycle\n";
    return 0;
}