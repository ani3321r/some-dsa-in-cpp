#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m,0));
    queue<pair<pair<int,int>, int>> q;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(grid[i][j] == 1){
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            } else{
                vis[i][j] = 0;
            }
        }
    }
    int delRow[] = {-1, 0, +1, 0};
    int delCol[] = {0, +1, 0, -1}; 
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        dist[row][col] = steps;
        for(int i=0; i<4; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0){
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, steps+1});
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
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    vector<vector<int>> ans = nearest(grid);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j];
            if (j < m - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}