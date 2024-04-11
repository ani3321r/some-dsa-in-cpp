#include<bits/stdc++.h>
using namespace std;

void ascending(int i, int n){
    if(i>n) return;
    cout << i << " ";
    ascending(i+1, n);
}

int main(){
    int num; 
    cin >> num;
    ascending(1, num);
}