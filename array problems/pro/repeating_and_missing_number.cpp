#include<bits/stdc++.h>
using namespace std;

vector<int> findMissingAndRepeating(vector<int> &a){
    long long n = a.size();
    int xr = 0;
    for(int i=0; i<n; i++){
        xr = xr ^ a[i];
        xr = xr ^ (i+1);
    }
    int num = xr & ~(xr-1);
    int zero = 0;
    int one = 0;
    for(int i=0; i<n; i++){
        if((a[i] & num) != 0){
            one  = one ^ a[i];
        }else{
            zero = zero ^ a[i];
        }
    }

    for(int i=1; i<=n; i++){
         if((i & num) != 0){
            one  = one ^ i;
        }else{
            zero = zero ^ i;
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++){
        if(a[i] == zero) cnt++;
    }
    if(cnt == 2) return {zero, one};
    return {one, zero};
}

int main(){
    vector<int> arr = {1, 3, 2, 2, 4};
    vector<int> ans = findMissingAndRepeating(arr);
    cout << "repeating: " << ans[0] << ", missing: " << ans[1]; 
    return 0;
}


//brute 
//sc O(1)
//tc O(n^2)

//better
//sc O(n)
//tc O(2n)

/*
vector<int> findMissingAndRepeating(vector<int> &a){
    int n = a.size();
    int hash[n+1] = {0};
    for(int i=0; i<n; i++){
        hash[a[i]]++;
    }
    int repeating = -1, missing = -1;
    for(int i=1; i<=n; i++){
        if(hash[i] == 2) repeating = i;
        else if(hash[i] == 0) missing = i;

        if(repeating != -1 && missing != -1){
            break;
        }
    }
    return {repeating, missing};
}
*/

//optimal (math)
//sc O(1)
//tc O(n) 

/*
vector<int> findMissingAndRepeating(vector<int> &a){
    long long n = a.size();
    long long sn = (n*(n+1)) / 2;
    long long s2n = (n*(n+1)*(2*n+1)) / 6;
    long long s = 0, s2 = 0;
    for(int i=0; i<n; i++){
        s += a[i];
        s2 = (long long)a[i]*(long long)a[i];
    }
    long long val1 = s-sn;
    long long val2 = s2-s2n;
    val2 = val2/val1;
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    return {(int)x, (int)y};
}
*/

//optimal (xor)
//sc O(1)
//tc O(n) 