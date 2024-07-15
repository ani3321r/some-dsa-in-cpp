#include <iostream>
#include <vector>
using namespace std;

int minPathSumTri(vector<vector<int>> &triangle, int n){
    vector<int> front(n, 0), cur(n, 0);
    for(int j=0; j<n; j++) front[j] = triangle[n-1][j];
    
    for(int i=n-2; i>=0; i--){
        for(int j=i; j>=0; j--){
            int d = triangle[i][j] + front[j];
            int dg = triangle[i][j] + front[j+1];
            cur[j] = min(d, dg);
        }
        front = cur;
    }
    return front[0];
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
    vector<vector<int>> triangle(n);
    for(int i = 0; i < n; i++) {
        triangle[i].resize(i + 1);
        for(int j = 0; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }
    int ans = minPathSumTri(triangle, n);
    cout << ans << endl;
    return 0;
}