#include<bits/stdc++.h>
#include<vector>
using namespace std;

int largestElement(vector<int> &arr, int n){
    int largest = arr[0];
    for(int i=0; i<n; i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    return largest;
}

int main(){
    init_code();
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << largestElement(arr, num);
    return 0;
}