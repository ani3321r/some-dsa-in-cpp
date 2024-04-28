#include<bits/stdc++.h>
using namespace std;

int subArrayMaxProduct(vector<int> &a, int n){
    int pre=1, suff=1;
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        if(pre == 0) pre = 1;
        if(suff == 0) suff = 1;
        pre = pre*a[i];
        suff = suff*a[n-i-1];
        ans = max(ans, max(pre, suff));
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
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << subArrayMaxProduct(arr, num);
    return 0;
}

//brute
//sc O(1)
//tc O(n^3)

//better
//sc O(1)
//tc O(n^2)

//optimal
//sc O(1)
//tc O(n) 