#include<bits/stdc++.h>
using namespace std;

int maxConsecutiveOne(vector<int> &a, int n){
    int maxi = 0;
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(a[i] == 1){
            cnt++;
            maxi = max(maxi, cnt);
        }
        else{
            cnt = 0;
        }
    }
    return maxi;
}

int main(){
    init_code();
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << maxConsecutiveOne(arr, num);    
    return 0;
}

//optimal case
//tc O(n)

