#include<bits/stdc++.h>
using namespace std;

vector<int> AllPrimeFactors(int N) {
    vector<int> v;
    for(int factor = 2; factor<=sqrt(N); factor++){
        if(N%factor==0) v.push_back(factor);
        while(N%factor==0){
            N/= factor;
        }
    }
    if(N!=1) v.push_back(N);
    return v;
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
    ans = AllPrimeFactors(a);
    for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
}