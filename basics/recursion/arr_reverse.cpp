#include<bits/stdc++.h>
using namespace std;

void revArray(int arr[], int i, int n) {
    if(i>=n/2) return;
    swap(arr[i], arr[n-i-1]);
    revArray(arr, i+1, n); 
}
int main() {
    int num;
    cin >> num;
    int arr[num];
    for(int i=0; i<num; i++) cin >> arr[i];
    revArray(arr, 0, num);
    for(int i=0; i<num; i++) cout << arr[i] << " ";
    return 0;
}
