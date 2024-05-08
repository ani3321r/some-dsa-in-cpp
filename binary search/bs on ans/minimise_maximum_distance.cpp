#include<bits/stdc++.h>
using namespace std;

int numberOfGasStations(vector<int> &arr, long double dist){
    int cnt = 0;
    for(int i=1; i<arr.size(); i++){
        int numberInBetween = ((arr[i] - arr[i-1])/dist);
        if((arr[i] - arr[i-1])/dist == numberInBetween*dist){
            numberInBetween--;
        }
        cnt += numberInBetween;
    }
    return cnt;
}

long double minimiseMaxDistance(vector<int> &arr, int k){
    int n = arr.size();
    long double low=0;
    long double high=0;
    for(int i=0; i<n-1; i++){
        high = max(high, (long double)(arr[i+1]-arr[i]));
    }
    long double diff = 1e-6;
    while(high-low>diff){
        long double mid = (low+high)/(2.0);
        int cnt = numberOfGasStations(arr, mid);
        if(cnt>k){
            low=mid;
        }else{
            high=mid;
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
    int num, d;
    cin >> num;
    cin >> d;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << minimiseMaxDistance(arr, d);
    return 0;
}