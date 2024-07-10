#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    vector<int> rank, parent, size;
        DisjointSet(int n){
            rank.resize(n+1, 0); 
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0; i<=n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUPar(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node] = findUPar(parent[node]);
        }
        
        void unionByRank(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_v] < rank[ulp_u]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionBySize(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

int spanningTree(int n, vector<vector<int>> &edges){
    DisjointSet ds(n);
    int cntExtras = 0;
    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        if(ds.findUPar(u) == ds.findUPar(v)){
            cntExtras++;
        }
        else{
            ds.unionBySize(u, v);
        }
    }
    int cntC = 0;
    for(int i=0; i<n; i++){
        if(ds.parent[i] == i) cntC++;
    }
    int ans = cntC - 1;
    if(cntExtras>=ans) return ans;
    return -1;
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
    vector<vector<int>> edges;
    for(int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        if(u >= 0 && u < V && v >= 0 && v < V) {
            edges.push_back({u, v});
        } else {
            cout << "Invalid vertex!" << endl;
            return 1;
        }
    }
    int result = spanningTree(V, edges);
    if(result != -1) {
        cout << "Minimum number of operations: " << result << endl;
    } else {
        cout << "It's not possible to make the graph connected." << endl;
    }
    return 0;
}