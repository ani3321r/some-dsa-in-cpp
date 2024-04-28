#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
        left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low]; 
    }
}
int cntPairs(vector<int> &arr, int low,int mid, int high){
    int right = mid+1;
    int cnt = 0;
    for(int i=low; i<=mid; i++){
        while(right <= high && arr[i] > 2*arr[right]) right++;
        cnt += (right - (mid+1));
    }
    return cnt;
}
int mS(vector<int> &arr, int low, int high){
    int cnt = 0;
    if(low == high) return cnt;
    int mid = (low+high)/2;
    cnt += mS(arr, low, mid);
    cnt += mS(arr, mid+1, high);
    cnt += cntPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return cnt;
}
int revPairs(vector<int> &arr, int n){
    return mS(arr,0, n-1);
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
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];

    cout << revPairs(arr, num);
    return 0;
}


//brute 
//sc O(1)
//tc O(n^2)


//optimal
//sc O(n)
//tc O(2nlog(n))
//in optimal case we have to say that we are distorting the array