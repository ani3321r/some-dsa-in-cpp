#include<bits/stdc++.h>
using namespace std;

bool search2dMatrix(vector<vector<int>> &mat,int target){
    int n = mat.size();
    int m = mat[0].size();
    int low=0, high=n*m-1;
    while(low<=high){
        int mid = (low + high)/2;
        int row = mid/m;
        int col = mid%m;
        if(mat[row][col] == target) return true;
        else if(mat[row][col] < target) low = mid+1;
        else high = mid-1;
    }
    return false;
}

int main(){
    vector<vector<int>> arr = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    int target = 4;
    cout << search2dMatrix(arr,target);
    return 0;
}
