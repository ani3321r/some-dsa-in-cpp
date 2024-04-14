#include<bits/stdc++.h>
using namespace std;

void leftRotateArr(int arr[], int n, int d){
    reverse(arr, arr+d);
    reverse(arr+d, arr+n);
    reverse(arr, arr+n);
}

int main(){
    init_code();
    int num;
    cin >> num;
    int arr[num];
    for(int i=0; i<num; i++) cin >> arr[i];
    int d;
    cin >> d;    
    leftRotateArr(arr, num, d);
    for(int i=0; i<num; i++) cout << arr[i] << " ";
    return 0;
}

//the extra space used is O(d) and the net space used is O(n+d) for brute force
//sc O(1) for optimal
//brute force
/*
void leftRotateArr(int arr[], int n, int d){
    d=d % n;
    int temp[d];
    for(int i=0; i<d; i++){
        temp[i] = arr[i];
    }
    for(int i=d; i<n; i++){
        arr[i-d] = arr[i];
    }
    for(int i=n-d; i<n; i++){
        arr[i] = temp[i-(n-d)];
    }
}
*/
