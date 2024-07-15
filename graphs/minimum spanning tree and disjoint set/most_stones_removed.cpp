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

int maxRemove(vector<vector<int>>& stones, int n) {
    if (n == 0) return 0;
    int maxRow = 0;
    int maxCol = 0;
    for(auto it : stones) {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }
    DisjointSet ds(maxRow + maxCol + 1);
    unordered_set<int> stoneNodes;
    for(auto it : stones) {
        int nodeRow = it[0];
        int nodeCol = it[1] + maxRow + 1;
        ds.unionBySize(nodeRow, nodeCol);
        stoneNodes.insert(nodeRow);
        stoneNodes.insert(nodeCol);
    }
    int cnt = 0;
    for(int node : stoneNodes) {
        if(ds.findUPar(node) == node) {
            cnt++;
        }
    }
    return n - cnt;
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    int n;
    cin >> n;
    vector<vector<int>> stones(n, vector<int>(2));
    for(int i = 0; i < n; i++) {
        cin >> stones[i][0] >> stones[i][1];
    }
    int result = maxRemove(stones, n);
    cout << "Maximum stones that can be removed: " << result << endl;
    return 0;
}