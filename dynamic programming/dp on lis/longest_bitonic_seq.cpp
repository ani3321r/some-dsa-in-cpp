#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int longestBitonic(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp1(n, 1);

    for(int i=0; i<n; i++){
        for(int prev=0; prev<i; prev++){
            if(arr[i] > arr[prev] && 1 + dp1[prev] > dp1[i]){
                dp1[i] = 1 + dp1[prev];
            }
        }
    }

    vector<int> dp2(n, 1);
    for(int i=n-1; i>=0; i--){
        for(int prev=n-1; prev>i; prev--){
            if(arr[i] > arr[prev] && 1 + dp2[prev] > dp2[i]){
                dp2[i] = 1 + dp2[prev];
            }
        }
    }
    int maxi = 0;
    for(int i=0; i<n; i++){
        maxi = max(maxi, dp1[i] + dp2[i] - 1);
    }
    return maxi;
    
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    int s;
    cin >> s;
    vector<int> arr(s);
    for(int i=0; i<s; i++) cin >> arr[i];
    
    int ans = longestBitonic(arr);
    cout << ans;
    
    return 0;
}