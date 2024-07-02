#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, int col, int color[], vector<vector<int>> &adj){
    color[node] = col;
    for(auto it : adj[node]){
        if(color[it] == -1){
            if(dfs(it, !col, color, adj)==false) return false;
        } else if(color[it] == col){
            return false;
        }
    }
    return true;
}

bool isBipartite(int V, vector<vector<int>> adj){
    int color[V];
    for(int i=0; i<V; i++) color[i] = -1;
    for(int i=0; i<V; i++){
        if(color[i] == -1){
            if(dfs(i, 0, color, adj) == false) return false;
        }
    }
    return true;
}

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main() {
    init_code();
    int v;
    cin >> v;
    vector<vector<int>> adj(v, vector<int>(v));
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> adj[i][j];
        }
    }
    
    cout << isBipartite(v, adj);
    return 0;
}