#include<bits/stdc++.h>
using namespace std;

int floorSqrt(int n){
    int low=1, high=n;
        while(low<=high){
            long long mid = (low+high)/2;
            long long val = (mid*mid);
            if(val<=n){
                low = mid + 1; 
            } else{
                high = mid - 1;
            }
        }
    return high;    
}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main(){
    init_code();
    int num;
    cin >> num;
    cout << floorSqrt(num);
    return 0;
}