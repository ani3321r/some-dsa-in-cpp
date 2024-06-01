#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;
    for(int i=0; i<nums.size(); i++){
        if(!dq.empty() && dq.front() == i-k) dq.pop_front();
        while(!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1) ans.push_back(nums[dq.front()]);
    }
    return ans;
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
    vector<int> arr1(n);
    for(int i=0; i<n; i++) cin >> arr1[i];
    cin >> k;
    vector<int> arr2 = maxSlidingWindow(arr1, k);
    for(int i=0; i<arr2.size(); i++) cout << arr2[i] << " ";
}