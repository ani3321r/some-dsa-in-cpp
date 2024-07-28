#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int matrixMulti(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for(int len = 2; len < n; len++) {
        for(int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for(int k = i; k < j; k++) {
                int steps = nums[i-1] * nums[k] * nums[j] + dp[i][k] + dp[k+1][j];
                dp[i][j] = min(dp[i][j], steps);
            }
        }
    }
    return dp[1][n-1];
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    int s;
    cin >> s;
    vector<int> arr(s);
    for(int i=0; i<s; i++) cin >> arr[i];
    
    int result = matrixMulti(arr);
    cout << result << endl;
    
    return 0;
}