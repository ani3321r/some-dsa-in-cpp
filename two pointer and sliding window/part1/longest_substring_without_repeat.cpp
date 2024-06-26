#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s){
    unordered_set<char> set;
    int i = 0, j = 0, n = s.size(), ans = 0;
    while( i<n && j<n){
        if(set.find(s[j]) == set.end()){
            set.insert(s[j++]);
            ans = max(ans, j-i);
        }
        else{
            set.erase(s[i++]); 
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
    cin >> str;
    cout << lengthOfLongestSubstring(str) << endl;
}