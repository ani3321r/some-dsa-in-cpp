#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int burstBaloons(int n, vector<int>& a) {
    a.push_back(1);
    a.insert(a.begin(), 1);
    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));
    for(int i=n; i>=1; i--){
        for(int j=1; j<=n; j++){
            if(i > j) continue;
            int maxi = INT_MIN;
            for(int ind=i; ind<=j; ind++){
                int cost = a[i-1]*a[ind]*a[j+1] + dp[i][ind-1] + dp[ind+1][j];
                maxi = max(maxi, cost);
            }
            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
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
    
    int result = burstBaloons(s,arr);
    cout << result << endl;
    
    return 0;
}