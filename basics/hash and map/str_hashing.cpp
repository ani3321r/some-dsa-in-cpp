#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int hash[26] = {0};
    for(int i=0; i<s.size(); i++){
        hash[s[i]- 'a']++;
    }

    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        cout << hash[c-'a'] << endl;
    }
}

//if the condition of lowercase is not given the code will be a bit different
/*
    int hash[256] = {0};
    for(int i=0; i<s.size(); i++){
        hash[s[i]]++;
    }

    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        cout << hash[c] << endl;
    }
*/