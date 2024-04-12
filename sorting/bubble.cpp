#include<bits/stdc++.h>
using namespace std;

void bubble(int arr[], int n){
    for(int i=n-1; i>=0; i--){
        int didSwap = 0;
        for(int j=0; j<=i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j+1], arr[j]);
                didSwap = 1;
            }
        }
        if(didSwap == 0) break;//if the array is in sorted order, then to reduce time complexity, this is used
    }
}

int main(){
    int num;
    cin >> num;
    int arr[num];
    for(int i=0; i<num; i++) cin >> arr[i];
    bubble(arr,num);
    for(int i=0; i<num; i++) cout << arr[i] << " ";
    return 0;
}
//the avarage and worst case time complexity for 
//bubble and selection is O(n^2)
//but in bubble the best case is O(n) but for the selection is O(n^2)