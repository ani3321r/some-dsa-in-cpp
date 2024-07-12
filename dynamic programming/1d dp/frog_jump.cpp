#include <bits/stdc++.h>
using namespace std;

int frogJump(int n, vector<int> &heights) {
    if (n <= 1) return 0;
    
    int prev = 0;
    int prev2 = 0;
    for (int i = 1; i < n; i++) {
        int fs = prev + abs(heights[i] - heights[i-1]);
        int ss = INT_MAX;
        if (i > 1) ss = prev2 + abs(heights[i] - heights[i-2]);
        int curi = min(fs, ss);
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
    vector<int> heights(n);
    for(int i=0; i<n; i++) cin >> heights[i];
    int ans = frogJump(n, heights);
    cout << ans << endl;
    return 0;
}