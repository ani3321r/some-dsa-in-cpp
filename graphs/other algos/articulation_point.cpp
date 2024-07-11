#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
        int timer = 0;
    private:
        void dfs(int node, int parent, vector<int> &vis, int tin[], int low[], vector<int> &mark, vector<int> adj[]){
            vis[node] = 1;
            tin[node] = low[node] = timer;
            timer++;
            int child = 0;
            for(auto it : adj[node]){
                if(it == parent) continue;
                if(!vis[it]){
                    dfs(it, node, vis, tin, low, mark, adj);
                    low[node] = min(low[node], low[it]);
                    if(low[it] >= tin[node] && parent != -1){
                        mark[node] = 1;
                    }
                    child++;
                }
                else{
                    low[node] = min(low[node], tin[it]);
                }
            }
            if(child>1 && parent == -1){
                mark[node] = 1;
            }
        }
    public:
        vector<int> articulationPoints(int n, vector<int> adj[]){
            vector<int> vis(n, 0);
            int tin[n];
            int low[n];
            vector<int> mark(n, 0);
            for(int i=0; i<n; i++){
                if(!vis[i]){
                    dfs(i, -1, vis, tin, low, mark, adj);
                }
            }
            vector<int> ans;
            for(int i=0; i<n; i++){
                if(mark[i] == 1){
                    ans.push_back(i);
                }
            }
            if(ans.size() == 0) return {-1};
            return ans;
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

    vector<int> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution solution;
    vector<int> result = solution.articulationPoints(n, adj);

    cout << "Articulation points:" << endl;
    if (result[0] == -1) {
        cout << "No articulation points" << endl;
    } else {
        for (int point : result) {
            cout << point << " ";
        }
        cout << endl;
    }

    return 0;
}