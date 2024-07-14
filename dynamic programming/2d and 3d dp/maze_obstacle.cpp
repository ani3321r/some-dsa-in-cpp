#include <iostream>
#include <vector>
using namespace std;

int mazeObstacle(int n, int m, vector<vector<int>> &mat){
    int mod = (int)(1e9 + 7);
    vector<int> prev(m, 0);
    for(int i=0; i<n; i++){
        vector<int> cur(m, 0);
        for(int j=0; j<m; j++){
            if(mat[i][j] == 1) cur[j] = 0;
            else if(i == 0 && j == 0) cur[j] = 1;
            else{
                int up = 0;
                int left = 0;
                if(i>0) up = prev[j];
                if(j>0) left = cur[j-1];
                cur[j] = (up + left) % mod;
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
    int ans = mazeObstacle(n, m, mat);
    cout << ans << endl;
    return 0;
}