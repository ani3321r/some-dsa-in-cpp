#include<bits/stdc++.h>
using namespace std;

int subArrayMax(vector<int> &a){
    int sum = 0;
    int maxi = INT_MIN;
    for(auto  it: a){
        sum += it;
        maxi = max(sum, maxi);
        if(sum < 0) sum = 0;
    }
    return maxi;
}

int main(){
    init_code();
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << subArrayMax(arr);
    return 0;
}
//brute force
//sc O(1)
//tc O(n^3)

//better 
//tc O(n^2)
//sc O(1)

//optimal(kadane's algo)
//sc O(1)
//tc O(n) 

