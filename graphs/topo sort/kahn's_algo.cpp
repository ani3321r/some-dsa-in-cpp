#include <bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> indegree(V, 0);
    for(int i = 0; i < V; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }
    queue<int> q;
    for(int i = 0; i < V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    if(topo.size() != V) {
        return {};
    }
    return topo;
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
        if(u >= 0 && u < V && v >= 0 && v < V) {
            adj[u].push_back(v);
        } else {
            cout << "Invalid vertex!" << endl;
            return 1;
        }
    }
    
    vector<int> ans = topoSort(V, adj);
    if(ans.empty()) {
        cout << "Graph contains a cycle!" << endl;
    } else {
        for(int i : ans) cout << i << " ";
        cout << endl;
    }
    return 0;
}