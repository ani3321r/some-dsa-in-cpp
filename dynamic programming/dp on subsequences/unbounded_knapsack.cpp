#include <iostream>
#include <vector>
using namespace std;

int unbKnap(vector<int> &wt, vector<int> &val, int n, int maxWt) {
    vector<int> prev(maxWt+1, 0), cur(maxWt+1, 0);
    for(int W=0; W<=maxWt; W++){
        prev[W] = ((int)(W/wt[0])) * val[0];
    }
    for(int ind=1; ind<n; ind++){
        for(int W=0; W<=maxWt; W++){
            int notTake = 0 + prev[W];
            int take = 0;
            if(wt[ind] <= W){
                take = val[ind] + cur[W - wt[ind]];
            }
            cur[W] = max(take, notTake);
        }
        prev = cur;
    }
    return prev[maxWt];
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
    vector<int> arr1(n), arr2(n);
    for(int i = 0; i < n; i++) cin >> arr1[i];
    for(int i = 0; i < n; i++) cin >> arr2[i];
    
    int res = unbKnap(arr1, arr2, n, k);
    cout << res << endl;
    
    return 0;
}

//a shorter approach
// int unbKnap(vector<int> &wt, vector<int> &val, int n, int maxWt) {
//     vector<int> dp(maxWt+1, 0);
//     for(int W=0; W<=maxWt; W++){
//         for(int i=0; i<n; i++){
//             if(wt[i] <= W){
//                 dp[W] = max(dp[W], dp[W-wt[i]] + val[i]);
//             }
//         }
//     }
//     return dp[maxWt];
// }