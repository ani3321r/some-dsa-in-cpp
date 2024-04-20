#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &a, int n){
    int mini = a[0];
    int maxiProfit = 0;
    for(int i=0; i<n; i++){
        int cost = a[i] - mini;
        maxiProfit = max(maxiProfit, cost);
        mini = min(mini, a[i]);
    }
    return maxiProfit;
}

int main(){
    init_code();
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << maxProfit(arr, num);
    return 0;
}

//optimal
//sc O(1)
//tc O(n) 

