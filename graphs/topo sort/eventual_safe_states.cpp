#include <bits/stdc++.h>
using namespace std;

vector<int> safeState(int V, vector<int> adj[]) {
    vector<int> adjRev[V];
    int indegree[V] = {0};
    for(int i=0; i<V; i++){
        for(auto it: adj[i]){
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    vector<int> safeNodes;
    for(int i=0; i<V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int node = q.front();
        q.pop();
        safeNodes.push_back(node);
        for(auto it: adjRev[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
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
    vector<int> result = safeState(V, adj);
    for(int i=0; i<result.size(); i++) cout << result[i] << " ";
    cout << endl;
    return 0;
}