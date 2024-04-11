#include<bits/stdc++.h>
using namespace std;

void decending(int i, int n){
    if(i<1) return;
    cout << i << " ";
    decending(i-1, n);
}

int main(){
    int num; 
    cin >> num;
    decending(num, num);
}