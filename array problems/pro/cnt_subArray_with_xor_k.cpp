#include<bits/stdc++.h>
using namespace std;

int subArrayXorK(vector<int> &a, int n, int k){
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;
    int cnt = 0;
    for(int i=0; i<n; i++){
        xr = xr ^ a[i];
        int x = xr^k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
    
}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main(){
    init_code();
    int num, k;
    cin >> num;
    cin >> k;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << subArrayXorK(arr, num, k);   
    return 0;
}


//brute 
//sc O(1)
//tc O(n^3) 

//better
//sc O(1)
//tc O(n^2)


//optimal
//sc O(n)
//tc O(nlog(n)) or O(n)

