#include<bits/stdc++.h>
using namespace std;

bool search(vector<vector<int>> &mat,int target){
    int n = mat.size();
    int m = mat[0].size();
    int row=0, col=m-1;
    while(row<n && col>=0){
        if(mat[row][col] == target) return true;
        else if(mat[row][col] < target) row++;
        else col--;
    }
    return false;
}

int main(){
    vector<vector<int>> arr = {{1, 4, 7},{2, 5, 8},{3, 6, 9}};
    int target = 10;
    cout << search(arr, target);
    return 0;
}
