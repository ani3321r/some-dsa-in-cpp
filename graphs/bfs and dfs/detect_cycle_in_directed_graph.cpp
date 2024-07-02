#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, int vis[], int pathVis[]){
    vis[node] = 1;
    pathVis[node] = 1;
    for(auto it: adj[node]){
        if(!vis[it]){
            if(dfs(it, adj, vis, pathVis)==true) return true;
        } else if(pathVis[it]){
            return true;
        }
    }
    pathVis[node] = 0;
    return false;
}

bool isCyclic(int v, vector<vector<int>> adj){
    int vis[v] = {0};
    int pathVis[v] = {0};
    for(int i=0; i<v; i++){
        if(!vis[i]){
            if(dfs(i, adj, vis, pathVis) == true) return true;
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
    int v;
    cin >> v;
    vector<vector<int>> adj(v, vector<int>(v));
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            cin >> adj[i][j];
        }
    }
    
    cout << isCyclic(v, adj);
    return 0;
}