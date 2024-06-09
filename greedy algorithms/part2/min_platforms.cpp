#include <bits/stdc++.h>
using namespace std;

int minPlatform(vector<int> &arr, vector<int> &dep, int n){
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int req_plat=1, res=1;
    int i=1, j=0;
    while(i<n && j<n){
        if(arr[i] <= dep[j]){
            req_plat++;
            i++;
        }
        else if(arr[i] > dep[j]){
            req_plat--;
            j++;
        }
        if(req_plat > res){
            res = req_plat;
        }
    }
    return res;
}

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main() {
    init_code();
    int n;
    cin >> n;
    vector<int> arr1(n), arr2(n);
    for (int i = 0; i < n; i++){
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++){
        cin >> arr2[i];
    }
    cout << minPlatform(arr1, arr2, n);
}