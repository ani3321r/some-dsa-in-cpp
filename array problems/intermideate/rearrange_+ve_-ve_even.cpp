#include<bits/stdc++.h>
using namespace std;

vector<int> rearrange(vector<int> &a, int n){
    vector<int> ans(n, 0);
    int posIndex = 0, negIndex = 1;
    for(int i=0; i<n; i++){
        if(a[i] < 0){
            ans[negIndex] = a[i];
            negIndex += 2;
        }
        else{
            ans[posIndex] = a[i];
            posIndex += 2;
        }
    }
    return ans;
}

int main(){
    init_code();
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    vector<int> arr2 = rearrange(arr, num);
    for(int i=0; i<num; i++) cout << arr2[i] << " ";
    return 0;
}
//brute force
//sc O(n)
//tc O(n + n/2)

//optimal
//sc O(1)
//tc O(n) 