#include<bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {  
    if(n < 0) {
        x = 1 / x;
    }
    long num = labs(n);
    double pow = 1;
    while(num){
        if(num & 1) {
            pow *= x;
        }
        x *= x;
        num >>= 1;
    }
    return pow;
}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main(){
    init_code();
    double a;
    int n;
    cin >> a;
    cin >> n;
    cout << myPow(a, n);
}