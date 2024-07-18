#include <iostream>
#include <vector>
using namespace std;

int minElements(int tar, vector<int> &nums) {
    int n = nums.size();
    vector<int> prev(tar+1, 0), cur(tar+1, 0);
    for(int T=0; T<=tar; T++){
        if(T%nums[0] == 0) prev[T] = T/nums[0];
        else prev[T] = 1e9;
    }
    for(int ind=1; ind<n; ind++){
        for(int T=0; T<=tar; T++){
            int notTake = 0 + prev[T];
            int take = INT_MAX;
            if(nums[ind] <= T){
                take = 1 + cur[T-nums[ind]];
            }
            cur[T] = min(take, notTake);
        }
        prev = cur;
    }
    int ans = prev[tar];
    if(ans >= 1e9) return -1;
    return ans;
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
    
    int res = minElements(k, arr);
    cout << res << endl;
    
    return 0;
}