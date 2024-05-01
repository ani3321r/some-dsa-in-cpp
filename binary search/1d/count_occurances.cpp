#include<bits/stdc++.h>
using namespace std;

int firstOccurance(vector<int> &a, int x){
    int n = a.size();
    int low=0, high=n-1;
    int first = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid] == x){
            first = mid;
            high = mid-1;
        }else if(a[mid]<x) low = mid + 1;
        else high = mid - 1;
    }
    return first;
}

int lastOccurance(vector<int> &a, int x){
    int n = a.size();
    int low=0, high=n-1;
    int last = -1;
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid] == x){
            last = mid;
            low = mid+1;
        }else if(a[mid]<x) low = mid + 1;
        else high = mid - 1;
    }
    return last;
}

pair<int,int> firstAndLast(vector<int>&a, int k){
    int first = firstOccurance(a,k);
    if(first == -1) return {-1, -1};
    int last = lastOccurance(a,k);
    return {first, last};
}

int count(vector<int>&a, int k){
    pair<int, int> ans = firstAndLast(a,k);
    if(ans.first == -1) return 0;
    return ans.second - ans.first + 1;
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
    cout << count(arr, target);
    return 0;
}