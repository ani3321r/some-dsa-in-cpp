#include <bits/stdc++.h>
using namespace std;

int CheapFlights(int n, vector<vector<int>> &flights, int src, int dst, int k){
    vector<pair<int, int>> adj[n];
    for(auto it : flights){
        adj[it[0]].push_back({it[1], it[2]});
    }
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;
        if(stops>k) continue;
        for(auto iter : adj[node]){
            int adjNode = iter.first;
            int edW = iter.second;
            if(cost + edW < dist[adjNode] && stops <= k){
                dist[adjNode] = cost + edW;
                q.push({stops+1, {adjNode, cost+edW}});
            }
        }
    }
    if(dist[dst] == 1e9) return -1;
    return dist[dst];
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
    
    vector<vector<int>> flights;
    for(int i = 0; i < m; i++) {
        int src, dst, price;
        cin >> src >> dst >> price;
        flights.push_back({src, dst, price});
    }
    
    int src, dst, k;
    cin >> src >> dst >> k;
    
    int result = CheapFlights(n, flights, src, dst, k);
    
    cout << result << endl;
    
    return 0;
}