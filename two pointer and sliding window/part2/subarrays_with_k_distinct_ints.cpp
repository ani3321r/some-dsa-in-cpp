#include<bits/stdc++.h>
using namespace std;

int findSubarray(vector<int> &nums, int k){
    unordered_map<int,int> map;
    int left = 0 , right = 0, ans = 0;
    while(right<nums.size()){
        map[nums[right]]++;
        while(map.size()>k){
            map[nums[left]]--;
            if(map[nums[left]]==0)map.erase(nums[left]);
            left++;
        }
        ans += right-left+1;
        right++;
    }
    return ans;
}

int subarrWithDistK(vector<int> &nums, int k){
    return findSubarray(nums, k) - findSubarray(nums, k-1);
}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}    

int main(){
    init_code();
    int n, k;
    cin >> n;
    cin >> k;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    cout << subarrWithDistK(nums, k) << endl;
}