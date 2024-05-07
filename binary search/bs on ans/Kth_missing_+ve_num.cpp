#include<bits/stdc++.h>
using namespace std;

int missingK(vector<int> &a, int n, int k){
    int low=0, high=n-1;
    while(low <= high){
        int mid = (low+high)/2;
        int missing = a[mid] - (mid+1);
        if(missing < k){
            low = mid + 1;
        } else{
            high = mid - 1;
        }
    }
    return k + high + 1;
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
    cout << missingK(arr, num, d);
    return 0;
}