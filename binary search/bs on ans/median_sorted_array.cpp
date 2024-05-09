#include<bits/stdc++.h>
using namespace std;

int median(vector<int> &a, vector<int> &b){
    int n1 = a.size();
    int n2 = b.size();
    if(n1>n2) return median(b,a);
    int low=0, high=n1;
    int left = (n1+n2+1)/2;
    int n = n1 + n2;
    while(low <= high){
        int mid1 = (low+high) >> 1;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if(mid1 < n1) r1 = a[mid1];
        if(mid2 < n2) r2 = b[mid2];
        if(mid2-1 >= 0) l1 = a[mid1-1];
        if(mid2-1 >= 0) l2 = b[mid2-1];
        if(l1 <= r2 && l2 <= r1){
            if(n%2 == 1) return max(l1, l2);
            return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }
        else if(l1 > r2) high = mid1-1;
        else low = mid1+1;
    }
    return 0;
}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main(){
    init_code();
    int num1, num2;
    cin >> num1;
    cin >> num2;
    vector<int> a(num1);
    vector<int> b(num2);
    for(int i=0; i<num1; i++) cin >> a[i];
    for(int i=0; i<num2; i++) cin >> b[i];
    cout << median(a, b);
    return 0;
}