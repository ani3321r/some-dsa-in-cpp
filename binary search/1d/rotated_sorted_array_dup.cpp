#include<bits/stdc++.h>
using namespace std;

bool search(vector<int> &a, int k){
    int n = a.size();
    int low=0, high=n-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid] == k) return true;
        if(a[low] == a[mid] && a[mid] == a[high]){
            low++, high--;
            continue;
        }

        if(a[low] <= a[mid]){
            if(a[low] <= k && k <= a[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        else{
            if(a[mid] <= k && k <= a[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
    }
    return false;
}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main(){
    init_code();
    int num, target;
    cin >> num;
    cin >> target;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << search(arr, target);
    return 0;
}