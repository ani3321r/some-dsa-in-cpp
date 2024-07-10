#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V,0);
    pq.push({0, 0});
    int sum = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        if(vis[node] == 1) continue;
        vis[node] = 1;
        sum += wt;
        for(auto it : adj[node]){
            int adjNode = it[0];
            int edW = it[1];
            if(!vis[adjNode]){
                pq.push({edW, adjNode});
            }
        }
    }
    return sum;
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
    
    vector<vector<int>> adj[V];
    
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    
    int mstWeight = spanningTree(V, adj);
    cout << "Weight of Minimum Spanning Tree: " << mstWeight << endl;
    
    return 0;
}