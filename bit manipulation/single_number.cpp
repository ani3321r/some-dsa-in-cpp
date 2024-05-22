#include<bits/stdc++.h>
using namespace std;


int singleNumber(vector<int>& nums) { 
    int ans=0;
    for(auto x:nums)
    ans^=x;
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
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    cout << singleNumber(arr);
}