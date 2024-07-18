#include <iostream>
#include <vector>
using namespace std;

int findWays(int tar, vector<int> &arr) {
    int mod = (int)(1e9+7);
    int n = arr.size();
    vector<int> prev(tar+1, 0), cur(tar+1, 0);
    if(arr[0] == 0)prev[0] = 2;
    else prev[0] = 1;
    if(arr[0] != 0 && arr[0] <= tar) prev[arr[0]] = 1;
    for(int ind=1; ind<n; ind++){
        for(int sum=0; sum<=tar; sum++){
            int notTake = prev[sum];
            int take = 0;
            if(arr[ind] <= sum) take = prev[sum-arr[ind]];
            cur[sum] = (notTake + take) % mod;
        }
        prev = cur;
    }
    return prev[tar];
}

int cntPartitions(int n, int d, vector<int> &arr){
    int totSum = 0;
    for(auto &it : arr) totSum += it;
    if(totSum-d < 0 || (totSum -d) % 2) return false;
    return findWays((totSum-d)/2, arr);
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
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    int res = cntPartitions(n, k, arr);
    cout << res << endl;
    
    return 0;
}