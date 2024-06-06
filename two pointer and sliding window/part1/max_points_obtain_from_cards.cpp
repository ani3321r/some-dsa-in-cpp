#include<bits/stdc++.h>
using namespace std;

int maxPoints(vector<int> &arr, int k){
    int lsum=0, rsum=0, maxSum=0;
    for(int i=0;  i<k; i++){
        lsum = lsum + arr[i];
    }
    maxSum = lsum;
    int rindex = arr.size() - 1;
    for(int i=k-1; i>=0; i--){
        lsum = lsum - arr[i];
        rsum = rsum + arr[rindex];
        rindex = rindex - 1;

        maxSum = max(maxSum, lsum+rsum);
    }
    return maxSum;
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
    cout << maxPoints(nums, k) << endl;
}