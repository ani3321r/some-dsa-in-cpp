#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end){
    while(start <= end){
        if(s[start++] != s[end--]){
            return false;
        }
    }
    return true;
}

void func(int index, string s, vector<string> &path, vector<vector<string>> &res){
    if(index == s.size()){
        res.push_back(path);
        return;
    }
    for(int i=index; i<s.size(); i++){
        if(isPalindrome(s, index, i)){
            path.push_back(s.substr(index, i-index+1));
            func(i+1, s, path, res);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s){
    vector<vector<string>> res;
    vector<string> path;
    func(0, s, path, res);
    return res;
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
    int n = str.size();

    vector<vector<string>> ans = partition(str);

    cout << "all the possible palindromes are:\n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
}