#include<bits/stdc++.h>
using namespace std;

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

int countSmallEqual(vector<vector<int>> &mat, int n, int m, int x){
    int cnt = 0;
    for(int i=0; i<n; i++){
        cnt += upperBound(mat[i], x);
    }
    return cnt;
}

int median(vector<vector<int>> &mat){
    int low=INT_MAX;
    int high=INT_MIN;
    int n = mat.size();
    int m = mat[0].size();
    for(int i=0; i<n; i++){
        low = min(low, mat[i][0]);
        high = max(high, mat[i][m-1]);
    }
    int req = (n*m)/2;
    while(low <= high){
        int mid = (low+high)/2;
        int smallEqual = countSmallEqual(mat, n, m, mid);
        if(smallEqual <= req) low = mid+1;
        else high = mid-1;
    }
    return low;
}

int main(){
    vector<vector<int>> arr = {{1, 4, 7},{2, 5, 8},{3, 6, 9}};
    cout << median(arr);
    return 0;
}