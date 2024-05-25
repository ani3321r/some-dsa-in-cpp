#include<bits/stdc++.h>
using namespace std;

vector<long long int> twoOddNum(vector<int> &Arr, long long int N){
    long long int xorr=0;
    for(int i=0; i<N; i++){
        xorr= xorr ^ Arr[i];
    }
    long long int rightmost= (xorr & (xorr-1)) ^ xorr;
    long long int b1=0;
    long long int b2=0;
    for(int i=0; i<N; i++){
        if(Arr[i] & rightmost){
            b1= b1 ^ Arr[i];
        }
        else{
            b2 = b2 ^ Arr[i];
        }

    }
    vector<long long int> res;
    res.push_back(b1);
    res.push_back(b2);
    sort(res.begin(),res.end(), greater<long long int>());

    return res;

}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main(){
    init_code();
    long long int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    vector<long long int> ans = twoOddNum(arr,n);
    for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
}