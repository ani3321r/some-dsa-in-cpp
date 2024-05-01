#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &a, int x){
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

int upperBound(vector<int> &a, int x){
    int n = a.size();
    int low=0, high=n-1;
    int ans = n;
    while(low <= high){
        int mid = (low+high)/2;
        if(a[mid] > x){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    return ans;
}

pair<int,int> firstAndLast(vector<int>&a, int k){
    int n = a.size();
    int lb = lowerBound(a,k);
    if(lb == n || a[lb] != k) return {-1, -1};
    return {lb, upperBound(a,k)-1};
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
    pair<int, int> ans = firstAndLast(arr, target);
    cout << "first occurance " << ans.first << " last occurance " << ans.second;
    return 0;
}

//tc 2*O(log n)
//sc O(1)