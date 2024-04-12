#include<bits/stdc++.h>
using namespace std;

void selection(int arr[], int n){
    for(int i=0; i<=n-2; i++){
        int mini = i;
        for(int j=i; j<=n-1; j++){
            if(arr[j]<arr[mini]) mini=j;
        }
        int temp = arr[mini];
        arr[mini] = arr[i];
        arr[i] = temp;
    }
}
int main(){
    int num;
    cin >> num;
    int arr[num];
    for(int i=0; i<num; i++) cin >> arr[i];
    selection(arr,num);
    for(int i=0; i<num; i++) cout << arr[i] << " ";
    return 0;
}