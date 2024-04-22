#include<bits/stdc++.h>
using namespace std;

void rotateMatrix(vector<vector<int>> &a, int n){
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            swap(a[i][j], a[j][i]);
        }
    }
    for(int i=0; i<n; i++){
        reverse(a[i].begin(), a[i].end());
    }
}

int main(){
    vector<vector<int>> matrix = {{2, 3, 4}, {1, 0, 1}, {6, 7, 8}};
    int n = matrix.size();
    rotateMatrix(matrix, n);

    cout << "The Final matrix is:\n";
    for (auto it : matrix) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}


//brute
//sc O(n^2)
//tc O(n^2)

//optimal
//sc O(1)
//tc O(n^2) + O(n^2)