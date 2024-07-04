#include <bits/stdc++.h>
using namespace std;

bool isPossible(int V, vector<pair<int, int>>& prerequisite) {
    vector<int> adj[V];
    for(auto it: prerequisites){
        adj[it.first].push_back(it.second);
    }


    int indegree[V] = {0};
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
        cnt++;
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    if(topo.size() == V) return true;
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
    vector<pair<int, int>> prerequisites;
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        if(u >= 0 && u < V && v >= 0 && v < V) {
            prerequisites.push_back({u, v});
        } else {
            cout << "Invalid vertex!" << endl;
            return 1;
        }
    }
    cout << (isPossible(V, prerequisites) ? "true" : "false");
    return 0;
}