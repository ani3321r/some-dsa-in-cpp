#include<bits/stdc++.h>
using namespace std;

int findMax(vector<int> &v){
    int maxi = INT_MIN;
    int n = v.size();
    for(int i=0; i<n; i++){
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

int calculateTotalHrs(vector<int> &v, int hrly){
    int totalH = 0;
    int n = v.size();
    for(int i=0; i<n; i++){
        totalH += ceil((double)v[i] / (double)hrly); 
    }
    return totalH;
}

int minimumRateToEat(vector<int> &v, int h){
    int low=1, high=findMax(v);
    while(low<=high){
        int mid = (low+high)/2;
        int totalH = calculateTotalHrs(v, mid);
        if(totalH <= h){
            high = mid-1;
        }else{
            low = mid + 1;
        }
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
    int num, targetHr;
    cin >> num;
    cin >> targetHr;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << singleElement(arr, targetHr);
    return 0;
}