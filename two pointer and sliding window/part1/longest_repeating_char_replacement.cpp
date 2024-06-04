#include<bits/stdc++.h>
using namespace std;

int charReplace(string s, int k){
    unordered_map<char, int> alph;
    int ans = 0;
    int l = 0;
    int r = 0;
    int maxf = 0;
    for (r = 0; r < s.size(); r++) {
        alph[s[r]] = 1 + alph[s[r]];
        maxf = max(maxf, alph[s[r]]);
        if ((r - l + 1) - maxf > k) {
            alph[s[l]] -= 1;
            l++;
        } else {
            ans = max(ans, (r - l + 1));
        }
    }
    return ans;
}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}    

int main(){
    init_code();
    string str;
    int k;
    cin >> str;
    cin >> k;
    cout << charReplace(str, k) << endl;
}