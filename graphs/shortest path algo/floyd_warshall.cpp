#include <bits/stdc++.h>
using namespace std;

void floyd_warshall(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == -1){
                matrix[i][j] = 1e9;
            }
            if(i == j) matrix[i][j] = 0;
        }
    }
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 1e9){
                matrix[i][j] = -1;
            }
        }
    }
}


void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    
    int n;
    cin >> n;
    
    vector<vector<int>> matrix(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    
    floyd_warshall(matrix);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}