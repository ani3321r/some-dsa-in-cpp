#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int> wt, vector<int> val, int n, int maxWt) {
    vector<int> prev(maxWt+1, 0);
    for(int W=wt[0]; W<= maxWt; W++) prev[W] = val[0];
    for(int ind=1; ind<n; ind++){
        for(int W=maxWt; W>=0; W--){
            int notTake = 0 + prev[W];
            int take = INT_MIN;
            if(wt[ind] <= W){
                take = val[ind] + prev[W-wt[ind]];
            }
            prev[W] = max(take, notTake);
        }
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
    
    int res = knapsack(arr1, arr2, n, k);
    cout << res << endl;
    
    return 0;
}