#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int minSubsetSumDiff(int n, vector<int> &arr) {
    int minElement = *min_element(arr.begin(), arr.end());
    int shift = minElement < 0 ? -minElement : 0;
    
    int totSum = 0;
    for(int i = 0; i < n; i++) {
        arr[i] += shift;
        totSum += arr[i];
    }
    
    int k = totSum;
    vector<bool> prev(k+1, false), cur(k+1, false);
    prev[0] = cur[0] = true;
    if(arr[0] <= k) prev[arr[0]] = true;
    
    for(int ind = 1; ind < n; ind++) {
        for(int target = 1; target <= k; target++) {
            bool notTake = prev[target];
            bool take = false;
            if(arr[ind] <= target) take = prev[target-arr[ind]];
            cur[target] = take | notTake;
        }
        prev = cur;
    }
    
    int mini = INT_MAX;
    for(int s1 = 0; s1 <= totSum/2; s1++) {
        if(prev[s1] == true) {
            mini = min(mini, abs((totSum - s1) - s1));
        }
    }
    
    return mini;
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    int res = minSubsetSumDiff(n, arr);
    cout << res << endl;
    
    return 0;
}