#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindrome(int i, int j, string s){
    while(i<j){
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int palinPart(string str) {
    int n = str.size();
    vector<int> dp(n+1, 0);
    dp[n] = 0;
    for(int i=n-1; i>=0; i--){
        int minCost = INT_MAX;
        for(int j=i; j<n; j++){
            if(isPalindrome(i, j, str)){
                int cost = 1 + dp[j+1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
    return dp[0] - 1;
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
    
    int result = palinPart(s);
    cout << result << endl;
    
    return 0;
}