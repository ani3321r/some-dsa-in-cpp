#include<bits/stdc++.h>
using namespace std;


int func(int N){
        if(N%4==0) return N;
        else if(N%4==1) return 1;
        else if(N%4==2) return N+1;
        else return 0;
    }

int findXOR(int l, int r) {
    return func(l-1)^func(r);
}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main(){
    init_code();
    int a, b;
    cin >> a;
    cin >> b;
    cout << findXOR(a, b);
}