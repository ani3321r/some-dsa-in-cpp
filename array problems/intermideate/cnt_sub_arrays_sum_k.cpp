#include<bits/stdc++.h>
using namespace std;

int subArrayWithGivenSum(vector<int> &a, int n, int k){
    unordered_map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0, cnt = 0;
    for(int i=0; i<n; i++){
        preSum += a[i];
        int remove = preSum - k;
        cnt += mpp[remove];
        mpp[preSum] += 1;
    }

    return cnt;
}

int main(){
    init_code();
    int num;
    cin >> num;
    int k;
    cin >> k;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << subArrayWithGivenSum(arr, num, k);    
    return 0;
}


//brute
//sc O(1)
//tc O(n^3)

//better
//sc O(1)
//tc O(n^2)

//optimal
//sc O(n)
//tc O(nlog(n))

