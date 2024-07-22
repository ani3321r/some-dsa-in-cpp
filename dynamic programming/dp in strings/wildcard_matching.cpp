#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool wildcard(string text, string pattern) {
    int n = pattern.size();
    int m = text.size();
    vector<bool> prev(m+1, false), cur(m+1, false);
    prev[0] = true;
    for(int j=1; j<=m; j++){
        prev[j] = false;
    }

    for(int i=1; i<=n; i++){
        bool flag = true;
        for(int ii=1; ii<=i; ii++){
            if(pattern[ii-1] != '*'){
                flag = false;
                break;
            }
        }
        cur[0] = flag;
        for(int j=1; j<=m; j++){
            if(pattern[i-1] == text[j-1] || pattern[i-1] == '?'){
                cur[j] = prev[j-1];
            }
            else if(pattern[i-1] == '*'){
                cur[j] = prev[j] | cur[j-1];
            }
            else{
                cur[j] = false;
            }
        }
        prev = cur;
    }
    return prev[m];
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
    
    bool result = wildcard(s, t);
    cout << result << endl;
    
    return 0;
}