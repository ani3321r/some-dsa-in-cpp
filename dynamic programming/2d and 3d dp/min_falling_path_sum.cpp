#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int minFallPathSum(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<int> prev(m, 0), cur(m, 0);

    for(int j = 0; j < m; j++) prev[j] = mat[0][j];

    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int up = mat[i][j] + prev[j];
            int leftDiag = j > 0 ? mat[i][j] + prev[j-1] : INT_MAX;
            int rightDiag = j < m-1 ? mat[i][j] + prev[j+1] : INT_MAX;
            
            cur[j] = min({up, leftDiag, rightDiag});
        }
        prev = cur;
    }

    return *min_element(prev.begin(), prev.end());
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
    int ans = minFallPathSum(mat);
    cout << ans << endl;
    return 0;
}