#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices, int n){
    vector<vector<int>> dp(n+2, vector<int>(2,0));
    for(int ind=n-1; ind>=0; ind--){
        dp[ind][1] = max(-prices[ind] + dp[ind+1][0], 0 + dp[ind+1][1]);
        dp[ind][0] = max(prices[ind] + dp[ind+2][1], 0 + dp[ind+1][0]);
    }
    return dp[0][1];
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
    vector<int> prices(s);
    for(int i=0; i<s; i++) cin >> prices[i];
    
    int result = maxProfit(prices, s);
    cout << result << endl;
    
    return 0;
}

//space optimised

// int maxProfit(vector<int> &prices, int n){
//     vector<int> f2(2, 0);
//     vector<int> f1(2, 0);
//     vector<int> cur(2, 0);
//     for(int ind=n-1; ind>=0; ind--){
//         cur[1] = max(-prices[ind] + f1[0], 0 + f1[1]);
//         cur[0] = max(prices[ind] + f2[1], 0 + f1[0]);

//         f2 = f1;
//         f1 = cur;
//     }
//     return cur[1];
// }