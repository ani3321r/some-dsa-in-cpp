#include<bits/stdc++.h>
using namespace std;

void ascending(int i, int n){
    if(i<1) return;
    ascending(i-1, n);
    cout << i << " ";
}

int main(){
    int num;
    cin >> num;
    ascending(num, num);
    return 0;
}