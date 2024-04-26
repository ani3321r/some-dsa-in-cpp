#include<bits/stdc++.h>
using namespace std;

int maxLen(vector<int> &a, int n){
    unordered_map<int, int> mpp;
    int maxi = 0;
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += a[i];
        if(sum == 0){
            maxi = i+1;
        }
        else{
            if(mpp.find(sum) != mpp.end()){
                maxi = max(maxi, i-mpp[sum]);
            }
            else{
                mpp[sum] = i;
            }
        }
    }
    return maxi+1;
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
    cout << maxLen(arr, num);    
    return 0;
}

//brute 
//sc O(1)
//tc O(n^3) 

//optimal
//sc O(n)
//tc O(nlog(n))
