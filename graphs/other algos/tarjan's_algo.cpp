#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
        int timer = 1;
    private:
        void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges){
            vis[node] = 1;
            tin[node] = low[node] = timer;
            timer++;
            for(auto it : adj[node]){
                if(it == parent) continue;
                if(vis[it] == 0){
                    dfs(it, node, vis, adj, tin, low, bridges);
                    low[node] = min(low[node], low[it]);
                    if(low[it] > tin[node]){
                        bridges.push_back({it, node});
                    }
                }
                else{
                    low[node] = min(low[node], low[it]);
                }
            }
        }
    public:
        vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections){
            vector<int> adj[n];
            for(auto it : connections){
                adj[it[0]].push_back(it[1]);
                adj[it[1]].push_back(it[0]);
            }
            vector<int> vis(n, 0);
            int tin[n];
            int low[n];
            vector<vector<int>> bridges;
            dfs(0, -1, vis, adj, tin, low, bridges);
            return bridges;
        }    
};

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();

    int n, m;
    cin >> n;
    cin >> m;

    vector<vector<int>> connections(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> connections[i][0] >> connections[i][1];
    }

    Solution solution;
    vector<vector<int>> result = solution.criticalConnections(n, connections);

    cout << "Critical connections:" << endl;
    for (const auto& connection : result) {
        cout << connection[0] << " - " << connection[1] << endl;
    }

    return 0;
}