#include<bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> &a, int n){
    int xorr = 0;
    for(int i=0; i<n; i++){
        xorr = xorr ^ a[i];
    }
    return xorr;
}

int main(){
    init_code();
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << getSingleElement(arr, num);    
    return 0;
}
//brute force
//sc O(1)
//tc O(n^2)

//better(hash) for big values it is not feasible
//tc O(n)
//sc(max^2)

//better(map) it can hold a whole lot of value using less space
//tc O(n/2 + 1) + O(nlog(n))
//sc O(n/2 + 1)

//optimal
//sc O(1)
//tc O(n)

