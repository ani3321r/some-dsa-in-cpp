#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination){
    queue<pair<int, pair<int, int>>> q;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[source.first][source.second] = 0;
    q.push({0, {source.first, source.second}});
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;
        for(int i=0; i<4; i++){
            int newr = r + dr[i];
            int newc = c + dc[i];
            if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]==1 && dis+1<dist[newr][newc]){
                dist[newr][newc] = 1 + dis;
                if(newr == destination.first && newc == destination.second) return dis+1;
                q.push({1+dis, {newr, newc}});
            }
        }
    }
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
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    int sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy;
    
    pair<int, int> source = {sx, sy};
    pair<int, int> destination = {dx, dy};
    
    int result = shortestPath(grid, source, destination);
    
    cout << result << endl;
    
    return 0;
}