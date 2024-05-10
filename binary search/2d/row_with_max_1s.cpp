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

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m){
    int cnt_max = 0;
    int index = -1;
    for(int i=0; i<n; i++){
        int cnt_ones = m - lowerBound(matrix[i], 1);
        if(cnt_ones > cnt_max){
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}

int main(){
    vector<vector<int>> arr = {{0,0,1,1,1},{1,1,1,1,0},{0,0,1,1,0},{0,1,1,1,1},{1,0,1,0,1}};
    cout << rowWithMax1s(arr, 5, 5);
    return 0;
}
