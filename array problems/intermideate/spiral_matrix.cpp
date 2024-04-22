#include<bits/stdc++.h>
using namespace std;

vector<int> spiralMatrix(vector<vector<int>> &a, int n, int m){
    int left = 0, right = m-1;
    int top = 0, bottom = n-1;
    vector<int> ans;

    while(top <= bottom && left <= right){

        for(int i=left; i<=right; i++){
            ans.push_back(a[top][i]);
        }
        top++;
        for(int i=top; i<=bottom; i++){
            ans.push_back(a[i][right]);
        }
        right--;
        if(top <= bottom){
            for(int i=right; i>=left; i--){
                ans.push_back(a[bottom][i]);
            }
        bottom--; 
        }
        if(left <= right){
            for(int i=bottom; i>=top; i--){
                ans.push_back(a[i][left]);
            }
        left++;
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> matrix = {{2, 3, 4, 5, 10, 78}, {89, 23, 1, 52, 36, 23}, {6, 7, 8, 45, 64, 69}, {61, 75, 88, 40, 65, 62}, {64, 79, 80, 47, 21, 17}};
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> arr2 = spiralMatrix(matrix, n, m);
    for(int i=0; i<n*m; i++) cout << arr2[i] << " ";
    return 0;
}

//optimal
//sc O(n^2)
//tc O(n^2)