#include<bits/stdc++.h>
using namespace std;

void summation(int i, int sum){
    if(i<1){
        cout << sum;
        return;
    }
    summation(i-1, sum+i);
}

int main(){
    int num;
    cin >> num;
    summation(num,0);
}