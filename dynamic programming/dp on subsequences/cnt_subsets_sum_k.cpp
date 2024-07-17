#include <iostream>
#include <vector>
using namespace std;

int findWays(int tar, vector<int> &arr) {
    int n = arr.size();
    vector<int> prev(tar+1, 0), cur(tar+1);
    prev[0] = cur[0] = 1;
    if(arr[0] <= tar) prev[arr[0]] = 1;
    for(int ind=1; ind<n; ind++){
        for(int sum=0; sum<=tar; sum++){
            int notTake = prev[sum];
            int take = 0;
            if(arr[ind] <= sum) take = prev[sum-arr[ind]];
            cur[sum] = notTake + take;
        }
        prev = cur;
    }
    return cur[tar];
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
    
    int res = findWays(k, arr);
    cout << res << endl;
    
    return 0;
}