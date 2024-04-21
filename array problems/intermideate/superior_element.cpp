#include<bits/stdc++.h>
using namespace std;

vector<int> superiorElement(vector<int> &a, int n){
    vector<int> ans;
    int maxi = INT_MIN;
    for(int i=n-1; i>=0; i--){
        if(a[i] > maxi){
            ans.push_back(a[i]);
        }
        maxi = max(maxi, a[i]);
    }

    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    init_code();
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    vector<int> arr2 = superiorElement(arr, num);
    for(int i=0; i<num; i++) cout << arr2[i] << " ";
    return 0;
}
//brute force
//sc(n)
//tc(n^2)

//optimal
//sc O(n)
//tc O(n) when sorting is not required
//tc O(n) + O(nlog(n)) when sorting is required 

