#include<bits/stdc++.h>
using namespace std;

int mini(vector<int> &a){
    int n = a.size();
    int low=0, high=n-1;
    int ans = INT_MAX;
    while(low <=  high){
        int mid = (low+high)/2;
        if(a[low] <= a[mid]){
            ans = min(ans,a[low]);
            low = mid+1;
        }
        else{
            high = mid-1;
            ans = min(ans, a[mid]);
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
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << mini(arr);
    return 0;
}

//a more optimised time complexity code
/*
int mini(vector<int> &a){
    int n = a.size();
    int low=0, high=n-1;
    int ans = INT_MAX;
    while(low <=  high){
        int mid = (low+high)/2;
        if(a[low] <= a[mid]){
            ans = min(ans,a[low]);
            break;
        }

        if(a[low] <= a[mid]){
            ans = min(ans, a[low]);
            low = mid + 1;
        }
        else{
            high = mid-1;
            ans = min(ans, a[mid]);
        }
    }
    return ans;
}
*/