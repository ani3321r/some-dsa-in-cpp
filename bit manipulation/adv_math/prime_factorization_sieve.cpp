#include<bits/stdc++.h>
using namespace std;

vector<bool>prime(2*5e6,1);
void sieve(int n) {
    int k = sqrt(n) + 1;
    for(int i=2; i*i<k; i++){
        if(prime[i]){
            for (int j = i * i; j <= k; j += i) {
                prime[j] = 0;
            }
        }
    }
}

vector<int> findPrimeFactors(int n) {
    vector<int>v;
    sieve(n);
    for(int i=2; i<=sqrt(n); i++){
        if(prime[i]) {
            while(n%i==0) {
                n/=i;
                v.push_back(i);
            }
        }
    }
    if(n>1)v.push_back(n);
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
    ans = findPrimeFactors(a);
    for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
}

//tc O(n*log(log n)) + O(θ + log n)
//sc O(n)