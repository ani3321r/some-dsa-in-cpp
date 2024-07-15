#include <iostream>
#include <vector>
using namespace std;

int minPathSum(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m, 0);
    for(int i=0; i<n; i++){
        vector<int> cur(m, 0);
        for(int j=0; j<m; j++){
            if(i==0 && j==0) cur[j] = grid[i][j];
            else{
                int up = grid[i][j];
                if(i>0) up += prev[j];
                else up += 1e9;

                int left = grid[i][j];
                if(j>0) left += cur[j-1];
                else left += 1e9;

                cur[j] = min(left, up);
            }
        }
        prev = cur;
    }
    return prev[m-1];
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
    vector<vector<int>> mat(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    int ans = minPathSum(mat);
    cout << ans << endl;
    return 0;
}