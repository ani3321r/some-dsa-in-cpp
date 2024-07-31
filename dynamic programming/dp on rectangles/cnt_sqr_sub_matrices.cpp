#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cntSquares(vector<vector<int>> &arr, int n, int m){
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int j=0; j<m; j++) dp[0][j] = arr[0][j];
    for(int i=0; i<n; i++) dp[i][0] = arr[i][0];
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            if(arr[i][j] == 0) dp[i][j] = 0;
            else{
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
            }
        }
    }
    int sum = 0; 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            sum += dp[i][j];
        }
    }
    return sum;
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
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    int result = cntSquares(mat, n, m);
    cout << result << endl;

    return 0;
}