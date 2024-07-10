#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, parent, size;
    public:
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
    
    DisjointSet ds(n);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        ds.unionByRank(u, v);
    }
    
    int source, target;
    cin >> source;
    cin >> target;
    
    if (ds.findUPar(source) == ds.findUPar(target)) {
        cout << "Node " << target << " is NOT disjoint from the source node " << source << endl;
    } else {
        cout << "Node " << target << " is disjoint from the source node " << source << endl;
    }
    
    return 0;
}