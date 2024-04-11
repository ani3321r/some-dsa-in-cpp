#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    if(n<=1) return n;
    return fib(n-1) + fib(n-2);
}

int main(){
    int num;
    cin >> num;
    for(int i=0; i<num; i++){
        cout << fib(i) << " ";
    }
    return 0;
}