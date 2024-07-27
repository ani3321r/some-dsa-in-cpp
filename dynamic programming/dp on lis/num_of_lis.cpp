#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int numOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1), cnt(n, 1);
    int maxi = 1;

    for (int i = 1; i < n; ++i) {
        for (int prev = 0; prev < i; prev++) {
            if (nums[i] > nums[prev] && 1+dp[prev] > dp[i]) {
                dp[i] = 1 + dp[prev];
                cnt[i] = cnt[prev];
            }
            else if(nums[prev] < nums[i] && 1+dp[prev] == dp[i]){
                cnt[i] += cnt[prev];
            }
        }
        maxi = max(maxi, dp[i]);
    }

    int nos = 0;
    for(int i=0; i<n; i++){
        if(dp[i] == maxi) nos += cnt[i];
    }
    return nos;
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
    
    long result = numOfLIS(arr);
    cout << result << endl;
    
    return 0;
}