#include <bits/stdc++.h>
using namespace std;

vector<int> bellman_ford(int v, vector<vector<int>> &edges, int s) {
    vector<int> dist(v, 1e8);
    dist[s] = 0;
    for(int i=0; i<v-1; i++){
        for(auto it : edges){
            int u = it[0];
            int e = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[e]){
                dist[e] = dist[u] + wt;
            }
        }
    }
    for(auto it : edges){
        int u = it[0];
        int e = it[1];
        int wt = it[2];
        if(dist[u] != 1e8 && dist[u]+wt < dist[e]){
            return {-1};
        }
    }
    return dist;
}


void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> edges;
    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u, v, wt});
    }
    
    int s;
    cin >> s;
    
    vector<int> result = bellman_ford(n, edges, s);
    
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}