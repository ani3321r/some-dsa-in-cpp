#include<bits/stdc++.h>
using namespace std;

int singleElement(vector<int> &a){
    int n = a.size();
    if(n==1) return a[0];
    if(a[0] != a[1]) return a[0];
    if(a[n-1] != a[n-2]) return a[n-1];
    int low=1, high=n-2;
    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid] != a[mid+1] && a[mid] != a[mid-1]){
            return a[mid];
        }
        if((mid%2 == 1 && a[mid] == a[mid-1])||(mid%2==0 && a[mid] == a[mid+1])){
            low = mid + 1;
        }
        else{
            high = mid-1;
        }
    }
    return -1;
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
    cout << singleElement(arr);
    return 0;
}