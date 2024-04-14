#include<bits/stdc++.h>
#include<vector>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while(i<j){
        while(arr[i]<=pivot && i<=high-1){
            i++;
        }
        while(arr[j]>pivot && j>=low+1){
            j--;
        }
        if(i<j) swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}
void qS(vector<int> &arr, int low, int high){
    if(low < high){
        int pIndex = partition(arr, low, high);
        qS(arr, low, pIndex-1);
        qS(arr, pIndex+1, high);
    }
}
vector<int> quickSort(vector<int> &arr){
    qS(arr, 0, arr.size()-1);
    return arr;
}


int main(){
    init_code();
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    quickSort(arr);
    for(int i=0; i<num; i++) cout << arr[i] << " ";
    return 0;
}
//time complexity nlog(n)
//space complexity O(1)

//for descending
/*
int partition (vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i<j){
        while(arr[i]>=pivot && i<=high-1){
            i++;
        }
        while(arr[j]<pivot && j>=low+1){
            j--;
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}
*/