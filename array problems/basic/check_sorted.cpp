#include<bits/stdc++.h>
#include<vector>
using namespace std;

int isSorted(vector<int> &a, int n){
    for(int i=1; i<n; i++){
        if(a[i]>=a[i-1]){

        }else{
            return false;
        }
    }
    return true;
}

int main(){
    init_code();
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << isSorted(arr, num);
    return 0;
}
//O(n)