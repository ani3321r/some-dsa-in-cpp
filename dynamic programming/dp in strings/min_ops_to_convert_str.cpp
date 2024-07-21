#include <iostream>
#include <vector>
using namespace std;

int lcs(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<int> prev(m+1, 0), cur(m+1, 0);
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(s[i-1] == t[j-1]){
                cur[j] = 1 + prev[j-1];
            } 
            else {
                cur[j] = max(prev[j], cur[j-1]);
            }
        }
        prev = cur;
    }
    return cur[m];
}

int numOfOps(string &str, string &ptr){
    return str.size() + ptr.size() - 2*lcs(str, ptr);
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
    
    int result = numOfOps(s, t);
    cout << result << endl;
    
    return 0;
}