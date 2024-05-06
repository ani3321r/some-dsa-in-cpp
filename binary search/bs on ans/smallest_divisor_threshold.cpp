#include<bits/stdc++.h>
using namespace std;

int sumByD(vector<int> &a, int div){
    int sum = 0;
    int n = a.size();
    for(int i=0; i<n; i++){
        sum = sum + ceil((double)(a[i]) / (double)(div));
    }
    return sum;
}

int smallestDivisor(vector<int> &a, int limit){
    int low=1, high=*max_element(a.begin(), a.end());
    while(low <= high){
        int mid = (low + high)/2;
        if(sumByD(a,mid) <= limit){
            high = mid-1; 
        } else{
            low = mid+1;
        }
    }
    return low;
}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main(){
    init_code();
    int num, limit;
    cin >> num;
    cin >> limit;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << smallestDivisor(arr, limit);
    return 0;
}