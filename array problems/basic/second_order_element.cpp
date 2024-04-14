#include<bits/stdc++.h>
#include<vector>
using namespace std;

int secondLargest(vector<int> &arr, int n){
    int largest = arr[0];
    int slargest = -1;
    for(int i=1; i<n; i++){
        if(arr[i] > largest){
            slargest = largest;
            largest = arr[i];
        }
        else if(arr[i] < largest && arr[i] > slargest){
            slargest = arr[i];
        }
    }
    return slargest;
}
int secondSmallest(vector<int> &arr, int n){
    int smallest = arr[0];
    int ssmallest = INT_MAX;
    for(int i=1; i<n; i++){
        if(arr[i]<smallest){
            ssmallest = smallest;
            smallest = arr[i];
        }
        else if(arr[i] != smallest && arr[i] < ssmallest){
            ssmallest = arr[i];
        }   
    }
    return ssmallest;
}

vector<int> getSecondOrder(vector<int> &arr, int n){
    int slargest = secondLargest(arr, n);
    int ssmallest = secondSmallest(arr,n);
    return {slargest, ssmallest};
}

int main(){
    init_code();
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    vector<int> element_arr = getSecondOrder(arr, num);
    cout << element_arr[0] << endl;
    cout << element_arr[1];
    return 0;
}