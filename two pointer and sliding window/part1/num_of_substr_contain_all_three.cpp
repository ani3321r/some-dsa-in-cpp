#include<bits/stdc++.h>
using namespace std;

int subStrWithAllThree(string s){
    int n = size(s);
    int i=0,j=0,count=0;
    unordered_map<char, int> mp;
    while(j<n){
        mp[s[j]]++;
        while(mp['a']>=1 && mp['b']>=1 && mp['c']>=1){
            count += (n - j);
            mp[s[i]]--;
            i++;
        }
        j++;
    }
    return count;
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
    cout << subStrWithAllThree(str) << endl;
}