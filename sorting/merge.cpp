#include<bits/stdc++.h>
#include<vector>
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
void mS(vector<int> &arr, int low, int high){
    if(low == high) return;
    int mid = (low+high)/2;
    mS(arr, low, mid);
    mS(arr, mid+1, high);
    merge(arr, low, mid, high);
}
void mergeSort(vector<int> &arr, int n){
    mS(arr, 0, n-1);
}

int main(){
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    mergeSort(arr,num);
    for(int i=0; i<num; i++) cout << arr[i] << " ";
    return 0;
}
//the best worst and the average time complexity is nlog(n)
//the worst space complexity is O(n)