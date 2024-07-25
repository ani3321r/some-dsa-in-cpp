#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

void printLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    int lastIndex = 0;
    for(int i=0; i<n; i++){
        hash[i] = i;
        for(int prev=0; prev<i; prev++){
            if(nums[prev] < nums[i] && 1+dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
            lastIndex = i;
        }
    }
    vector<int> temp;
    temp.push_back(nums[lastIndex]);
    while(hash[lastIndex] != lastIndex){
        lastIndex = hash[lastIndex];
        temp.push_back(nums[lastIndex]);
    }
    reverse(temp.begin(), temp.end());
    for(auto it : temp) cout << it << " ";
    cout << endl;
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
    
    printLIS(arr);
    
    return 0;
}