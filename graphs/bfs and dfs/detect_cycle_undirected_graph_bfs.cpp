#include <bits/stdc++.h>
using namespace std;

bool detect(int src, vector<int> adj[], int vis[]){
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(auto adjecentNode : adj[node]){
            if(!vis[adjecentNode]){
                vis[adjecentNode] = 1;
                q.push({adjecentNode, node});
            } else if(parent != adjecentNode){
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<int> adj[]){
    int vis[V] = {0};
    for(int i=0; i<V; i++){
        if(!vis[i]){
            if(detect(i, adj, vis)) return true;
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