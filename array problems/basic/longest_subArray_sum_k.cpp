#include<bits/stdc++.h>
using namespace std;

int getSingleElement(vector<int> a, long long k){
    int left = 0, right = 0;
    long long sum = a[0];
    int maxLen = 0;
    int n = a.size();
    while(right < n){
        while(left <= right && sum > k){
            sum -= a[left];
            left++;
        }
        if(sum == k){
            maxLen = max(maxLen, right-left+1);
        }
        right++;
        if(right<n) sum += a[right];
    }
    return maxLen;
}

int main(){
    init_code();
    int num;
    cin >> num;
    int sum;
    cin >> sum;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << getSingleElement(arr, sum);    
    return 0;
}
//brute force
//sc O(1)
//tc O(n^2)

//better(this is the optimal in case zeros -ve +ve all are included)
//tc O(nlog(n)) for ordered map and O(n^2) for unordered
//sc O(n)

/*
int longestSubArraySumK(vector<int> &a, long long k){
    map<long long, int> perSumMap;
    long long sum = 0;
    int maxLen = 0;
    for(int i=0; i<a.size(); i++){
        sum += a[i];
        if(sum == k){
            maxLen = max(maxLen, i+1);
        }
        long long rem = sum - k;
        if(perSumMap.find(rem) != preSumMap.end()){
            int len = i - preSumMap[rem];
            maxLen = max(maxLen, len);
        }
        if(perSumMap.find(rem) != preSumMap.end()){
            preSumMap[sum] = i;
        }
    }        
    return maxLen;
}
*/


//optimal(for zeros and +ve)
//sc O(1)
//tc O(2n)

