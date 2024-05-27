#include<bits/stdc++.h>
using namespace std;

int countPrimes(int n) {
    vector<int> prime(n + 1, 1);
    for (int i = 2; i * i <= n; i++) {
        if (prime[i] == 1) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 2; i < n; i++) {
        if (prime[i] == 1) 
            ans++;
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
    int a;
    cin >> a;
    cout << countPrimes(a);
}

//tc O(n) + O(n*log(log n)) + O(n)
//sc O(n) 