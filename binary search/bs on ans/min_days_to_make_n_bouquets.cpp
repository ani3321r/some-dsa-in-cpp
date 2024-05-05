#include<bits/stdc++.h>
using namespace std;

int possible(vector<int> &arr, int day, int m, int k){
    int cnt=0;
    int noOfBoq=0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] <= day){
            cnt++;
        }
        else{
            noOfBoq += (cnt/k);
            cnt=0;
        }
    }
    noOfBoq += (cnt/k);
    return noOfBoq >= m;
}

int roseGarden(vector<int> &arr, int r, int b){
    long long val = r*1LL*b*1LL;
    if(val > arr.size()) return -1;
    int mini = INT_MAX, maxi = INT_MIN;
    for(int i=0; i<arr.size(); i++){
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    int low = mini, high = maxi;
    while(low <= high){
        int mid = (low+high)/2;
        if(possible(arr, mid, r, b)){
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return low;
}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main(){
    init_code();
    int num, r, b;
    cin >> num;
    cin >> b;
    cin >> r;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << roseGarden(arr, b, r);
    return 0;
}