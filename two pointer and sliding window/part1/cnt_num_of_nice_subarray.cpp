#include<bits/stdc++.h>
using namespace std;

int subArray(vector<int>& nums, int k) {
    int count = 0, ans = 0, start = 0, end = 0;
    int n = nums.size();
    while(end<n){
        if(nums[end]%2==1){
            count++;
        }
        while(count>k){
            if(nums[start]%2==1){
                count--;
            }
            start++;
        }
        ans += end-start+1;
        end++;
    }
    return ans;
}

int niceSubarray(vector<int>& nums, int k){
    return subArray(nums, k) - subArray(nums, k - 1);
}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}    

int main(){
    init_code();
    int n,k;
    cin >> n;
    cin >> k;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    cout << niceSubarray(nums, k) << endl;
}