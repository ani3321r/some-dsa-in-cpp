#include<bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) {
    unordered_map<int, int> count;
    count[0] = 1;
    int curr_sum = 0;
    int total_subarrays = 0;
    for (int num : nums) {
        curr_sum += num;
        if (count.find(curr_sum - goal) != count.end()) {
            total_subarrays += count[curr_sum - goal];
        }
        count[curr_sum]++;
    }
    return total_subarrays;
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
    cout << numSubarraysWithSum(nums, k) << endl;
}