#include <bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &heights, int k) {
    if (n <= 1) return 0;
    
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j <= k && i-j >= 0; j++) {
            int jump = dp[i-j] + abs(heights[i] - heights[i-j]);
            dp[i] = min(jump, dp[i]);
        }
    }
    
    return dp[n-1];
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    int n, k;
    cin >> n >> k;
    vector<int> heights(n);
    for(int i=0; i<n; i++) cin >> heights[i];
    int ans = frogJump(n, heights, k);
    cout << ans << endl;
    return 0;
}