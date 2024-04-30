#include<bits/stdc++.h>
using namespace std;

int searchPos(vector<int> &a, int x){
    int n = a.size();
    int low=0, high=n-1;
    int ans = n;
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid] >= x){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main(){
    init_code();
    int num, target;
    cin >> num;
    cin >> target;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << searchPos(arr, target);
    return 0;
}