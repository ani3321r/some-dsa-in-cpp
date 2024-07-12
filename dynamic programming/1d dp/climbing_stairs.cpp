#include <bits/stdc++.h>
using namespace std;

int climbingStairs(int n) {
    if (n <= 1) return 1;
    
    int prev = 1; 
    int prev2 = 1; 
    
    for (int i = 2; i <= n; i++) {
        int curi = prev + prev2;
        prev2 = prev;
        prev = curi;
    }
    
    return prev;
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
    int ans = climbingStairs(n);
    cout << ans << endl;
    return 0;
}