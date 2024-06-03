#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestConcOnes(vector<int> &nums, int k){
    int l=0, r=0, zeros=0, maxLen=0;
    while(r<nums.size()){
        if(nums[r]==0) zeros++;
        if(zeros>k){
            if(nums[l] == 0) zeros--;
            l++;   
        }    
        if(zeros <= k){
            l = r-l+1;
            maxLen = max(maxLen, l);
        }
        r++;
    }
    return maxLen;
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
    cout << lengthOfLongestConcOnes(nums, k) << endl;
}