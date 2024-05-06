#include<bits/stdc++.h>
using namespace std;

int findDays(vector<int> &weights, int cap){
    int days=1, load=0;
    for(int i=0; i<weights.size(); i++){
        if(weights[i] + load > cap){
            days += 1;
            load = weights[i];
        } else{
            load += weights[i];
        }
    }
    return days;
}

int leastWeight(vector<int> &weights, int d){
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    while(low <= high){
        int mid = (low+high)/2;
        int numberOfDays = findDays(weights, mid);
        if(numberOfDays <= d){
            high = mid - 1;
        } else{
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
    int num, d;
    cin >> num;
    cin >> d;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << leastWeight(arr, d);
    return 0;
}