#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void backtrack(int i, int j, string& current, set<string>& result, const string& s, const string& t, const vector<vector<int>>& dp) {
    if(i == 0 || j == 0) {
        result.insert(string(current.rbegin(), current.rend()));
        return;
    }
    
    if(s[i-1] == t[j-1]) {
        current.push_back(s[i-1]);
        backtrack(i-1, j-1, current, result, s, t, dp);
        current.pop_back();
    } else {
        if(dp[i-1][j] >= dp[i][j-1])
            backtrack(i-1, j, current, result, s, t, dp);
        if(dp[i][j-1] >= dp[i-1][j])
            backtrack(i, j-1, current, result, s, t, dp);
    }
}

vector<string> all_longest_common_subsequences(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(s[i-1] == t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    set<string> result_set;
    string current;
    backtrack(n, m, current, result_set, s, t, dp);
    
    vector<string> result(result_set.begin(), result_set.end());
    return result;
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    string s, t;
    cin >> s >> t;
    
    vector<string> result = all_longest_common_subsequences(s, t);
    for(const string& lcs : result) {
        cout << lcs << " ";
    }
    cout << endl;
    
    return 0;
}