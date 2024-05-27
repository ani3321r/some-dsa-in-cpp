#include<bits/stdc++.h>
using namespace std;

vector<int> printDivisors(int n) {
    vector<int> ans;
    for(int i=1; i<=sqrt(n); i++){
        if(n%i==0){
            ans.push_back(i);
            if(n/i != i) ans.push_back(n/i);
        }
    }
    sort(ans.begin(), ans.end());
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
    int a;
    cin >> a;
    vector<int> ans;
    ans = printDivisors(a);
    for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
}