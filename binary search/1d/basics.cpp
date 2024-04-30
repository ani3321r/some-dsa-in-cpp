#include<bits/stdc++.h>
using namespace std;

//iterative
int search_i(vector<int> &a, int target){
    int n = a.size();
    int low=0, high=n-1;
    while(low<=high){
        int mid = (int)(low+high)/2;
        if(a[mid]==target) return mid;
        else if(target>a[mid]) low=mid-1;
        else high = mid - 1;
    }
    return -1;
}

//recurssive
int bs(vector<int> &a, int low, int high, int target){
    if(low>high) return -1;
    int mid = (low+high)/2;
    if(a[mid]==target) return mid;
    else if(target>a[mid]) return bs(a, mid+1, high, target);
    return bs(a, low, high-1, target);
}

int search_r(vector<int> &a, int target){
    return bs(a, 0, a.size()-1, target);
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
    cout << search_r(arr, target);
    return 0;
}

//tc O(log n) (base 2 as search space is decreasing by a factor of two)

//for overflow case we must take mid = low + (high-low)/2