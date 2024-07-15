#include <iostream>
#include <vector>
using namespace std;

int maxFallPathSum(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();
    vector<int> prev(m, 0), cur(m,0);

    for(int j=0; j<m; j++) prev[j] = mat[0][j];
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            int u = mat[i][j] + prev[j];
            int ld = mat[i][j];
            if(j-1>=0) ld += prev[j-1];
            else ld += -1e8;
            int rd = mat[i][j];
            if(j+1<m) rd += prev[j+1];
            else rd += -1e8;
            cur[j] = max(u, max(ld, rd));
        }
        prev = cur; 
    }

    int maxi = -1e8;
    for(int j=0; j<m; j++){
        maxi = max(maxi, prev[j]);
    }
    
    return maxi;
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
    int ans = maxFallPathSum(mat);
    cout << ans << endl;
    return 0;
}