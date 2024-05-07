#include<bits/stdc++.h>
using namespace std;

int canWePlace(vector<int> &a, int dist, int cows){
    int cntCows = 1, last = a[0];
    for(int i=1; i<a.size(); i++){
        if(a[i]-last >= dist){
            cntCows++;
            last = a[i];
        }
        if(cntCows >= cows) return true;
    }
    return false;
}

int aggressiveCows(vector<int> &arr, int k){
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int low=1, high=arr[n-1]-arr[0];
    while(low<=high){
        int mid = (low+high)/2;
        if(canWePlace(arr, mid, k)==true){
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }
    return high;
}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main(){
    init_code();
    int num, b;
    cin >> num;
    cin >> b;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << aggressiveCows(arr, b);
    return 0;
}