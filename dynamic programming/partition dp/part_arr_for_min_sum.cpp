#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSum(int k, vector<int>& num) {
    int n = num.size();
    vector<int> dp(n+1, 0);
    for(int ind=n-1; ind>=0; ind--){
        int len = 0;
        int maxi = INT_MIN;
        int maxAns = INT_MIN;
        for(int j=ind; j<min(ind+k,n); j++){
            len++;
            maxi = max(maxi, num[j]);
            int sum = len*maxi + dp[j+1];
            maxAns = max(maxAns, sum);
        }
        dp[ind] = maxAns;
    }
    return dp[0];
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    int s, k;
    cin >> s >> k;
    vector<int> arr(s);
    for(int i=0; i<s; i++) cin >> arr[i];
    
    int result = minSum(k,arr);
    cout << result << endl;
    
    return 0;
}