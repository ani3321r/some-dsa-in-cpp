#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> adjLs[], int vis[]){
    vis[node] = 1;
    for(auto it: adjLs[node]){
        if(!vis[it]){
            dfs(it, adjLs, vis);
        }
    }
}

int numProvinces(vector<vector<int>> adj, int V){
    vector<int> adjLs[V];
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(adj[i][j] == 1 && i != j){
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }
    int vis[V] = {0};
    int cnt = 0;
    for(int i=0; i<V; i++){
        if(!vis[i]){
            cnt++;
            dfs(i, adjLs, vis);
        }
    }
    return cnt;
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
    
    cout << numProvinces(adj, v);
    return 0;
}