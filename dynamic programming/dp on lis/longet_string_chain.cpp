#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

bool checkPossible(string &s1, string &s2){
    if(s1.size() != s2.size() + 1) return false;
    int first = 0;
    int second = 0;
    while(first < s1.size()){
        if(second < s2.size() && s1[first] == s2[second]){
            first++;
            second++;
        }
        else{
            first++;
        }
    }
    if(first == s1.size() && second == s2.size()) return true;
    return false;
}

bool comp(string &s1, string &s2){
    return s1.size() < s2.size();
}

int longestStr(vector<string>& strs) {
    sort(strs.begin(), strs.end(), comp);
    int n = strs.size();
    vector<int> dp(n, 1);
    int maxi = 1;
    for(int i=0; i<n; i++){
        for(int prev=0; prev<i; prev++){
            if(checkPossible(strs[i], strs[prev]) && 1 + dp[prev] > dp[i]){
                dp[i] = 1 + dp[prev];
            }
        }
        if(dp[i] > maxi){
            maxi = dp[i];
        }
    }
    return maxi;
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    int s;
    cin >> s;
    vector<string> arr(s);
    for(int i=0; i<s; i++) cin >> arr[i];
    
    int ans = longestStr(arr);
    cout << ans;
    
    return 0;
}