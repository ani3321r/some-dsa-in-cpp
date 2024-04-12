#include<bits/stdc++.h>
using namespace std;

void insertion(int arr[], int n){
    for(int i=0;i<=n-1;i++){
        int j = i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}

int main(){
    int num;
    cin >> num;
    int arr[num];
    for(int i=0; i<num; i++) cin >> arr[i];
    insertion(arr,num);
    for(int i=0; i<num; i++) cout << arr[i] << " ";
    return 0;
}
//the worst and average time complexity is O(n^2)
//the best is O(n)