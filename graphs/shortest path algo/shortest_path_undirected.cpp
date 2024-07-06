#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<vector<int>>& edges, int n, int m, int src) {
    vector<int> adj[n];
    for(auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    int dist[n];
    for(int i=0; i<n; i++) dist[i] = 1e9;
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it: adj[node]){
            if(dist[node]+1 < dist[it]){
                dist[it] = 1 + dist[node];
                q.push(it);
            }
        }
    }
    vector<int> ans(n, -1);
    for(int i=0; i<n; i++){
        if(dist[i] != 1e9){
            ans[i] = dist[i];
        }
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
    
    int n, m, src;
    cin >> n >> m >> src;
    
    vector<vector<int>> edges(m, vector<int>(2));
    for(int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    
    vector<int> result = shortestPath(edges, n, m, src);
    
    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}