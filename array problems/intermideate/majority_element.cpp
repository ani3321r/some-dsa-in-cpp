#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int> &a, int n){
    int cnt = 0;
    int el;
    for(int i=0; i<n; i++){
        if(cnt == 0){
            cnt = 1;
            el = a[i];
        }
        else if(a[i] == el){
            cnt++;
        }
        else{
            cnt--;
        }
    }
    int cnt1 = 0;
    for(int i=0; i<n; i++){
        if(a[i] == el) cnt1++;
    }
    if(cnt1 > (n/2)){
        return el;
    }
    return -1;
}

int main(){
    init_code();
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << majorityElement(arr, num);
    return 0;
}
//brute force
//sc O(1)
//tc O(n^2)

//better (hashing)
//tc O(nlog(n)) + O(n)
//sc O(n)
/*
int majorityElement(vector<int> a){
    unordered_map<int, int> mpp;
    for(int i=0; i<a.size(); i++){
        mpp[a[i]]++;
    }
    for(auto it: mpp){
        if(it.second > (a.size()/2)){
            return it.first;
        }
    }
    return -1;
}
*/

//optimal(moore's voting algo)
//sc O(1)
//tc O(n) 

