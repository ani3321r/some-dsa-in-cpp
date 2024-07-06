#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st){
    vis[node] = 1;
    for(auto it : adj[node]){
        int v = it.first;
        if(!vis[v]){
            topoSort(v, adj, vis, st);
        }
    }
    st.push(node);
}

vector<int> shortestPath(vector<int> edges[], int n, int m) {
    vector<pair<int, int>> adj[n];
    for(int i=0; i<n; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }
    int vis[n] = {0};
    stack<int> st;
    for(int i=0; i<n; i++){
        if(!vis[i]){
            topoSort(i, adj, vis, st);
        }
    }
    vector<int> dist(n);
    for(int i=0; i<n; i++) dist[i] = INT_MAX;
    dist[0] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        for(auto it : adj[node]){
            int v = it.first;
            int wt = it.second;
            if(dist[node] + wt < dist[v]){
                dist[v] = dist[node] + wt;
            }
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
    
    vector<int> edges[m];
    for(int i = 0; i < m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges[i] = {u, v, wt};
    }
    
    vector<int> result = shortestPath(edges, n, m);
    
    for(int i = 0; i < n; i++) {
        if(result[i] == INT_MAX)
            cout << "INF ";
        else
            cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}