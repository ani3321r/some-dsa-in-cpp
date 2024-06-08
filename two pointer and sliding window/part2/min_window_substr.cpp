#include<bits/stdc++.h>
using namespace std;

string minWindowSubStr(string s, string t) {
    int n = s.size();
    int m = t.size();
    int l = 0, r = 0, minLen = INT_MAX, sIndex = -1;
    unordered_map<char, int> hash;
    for (char c : t) {
        hash[c]++;
    }
    int required = hash.size();
    int formed = 0;
    while (r < n) {
        char currentChar = s[r];
        if (hash.count(currentChar)) {
            hash[currentChar]--;
            if (hash[currentChar] == 0) {
                formed++;
            }
        }
        while (formed == required) {
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                sIndex = l;
            }
            char leftChar = s[l];
            if (hash.count(leftChar)) {
                hash[leftChar]++;
                if (hash[leftChar] > 0) {
                    formed--;
                }
            }
            l++;
        }
        r++;
    }
    return sIndex == -1 ? "" : s.substr(sIndex, minLen);
}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}    

int main(){
    init_code();
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << minWindowSubStr(str1, str2) << endl;
}