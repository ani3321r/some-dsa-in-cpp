#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lcs(string s, string t){
    int n = s.size();
    int m = t.size();
    vector<int> prev(m+1, 0), cur(m+1, 0);
    int ans = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1] == t[j-1]){
                cur[j] = 1 + prev[j-1];
                ans = max(ans, cur[j]);
            } 
            else cur[j] = 0;
        }
        prev = cur;
    }
    return ans;
}

int longestPalin(string s){
    string t = s;
    reverse(t.begin(), t.end());
    return lcs(s,t);
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    string s;
    cin >> s;
    
    int result = longestPalin(s);
    cout << result << endl;
    
    return 0;
}