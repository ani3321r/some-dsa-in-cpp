#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &a, int n){
    int xor1 = 0, xor2 = 0;
    int n1 = n-1;
    for(int i=0; i<n1; i++){
        xor2 = xor2 ^ a[i];
        xor1 = xor1 ^ (i+1);
    } 
    xor1 = xor1 ^ n;
    return xor1 ^ xor2;
}

int main(){
    init_code();
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << missingNumber(arr, num);    
    return 0;
}
//brute force
//sc O(1)
//tc O(n * n)

//better
//sc O(n)
//tc O(n) + O(n)

//optimal case(add)
//sc O(1) 
//tc O(n)

//optimal case(xor)
//tc O(n)

//the xor is better than add as the add exceds the data limit at 10^5 whereas xor has no limit