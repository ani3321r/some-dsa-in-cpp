#include<bits/stdc++.h>
using namespace std;

void sortArray(vector<int> &a, int n){
    int low=0, mid=0, high=n-1;
    while(mid<=high){
        if(a[mid] == 0){
            swap(a[low], a[mid]);
            low++;
            mid++;
        }
        else if(a[mid] == 1){
            mid++;
        }
        else{
            swap(a[mid], a[high]);
            high--;
        }
    }
}

int main(){
    init_code();
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    sortArray(arr, num);   
    for(int i=0; i<num; i++) cout << arr[i] << " "; 
    return 0;
}
//brute force
//sc O(n)
//tc O(nlog(n))

//better 
//tc O(2n)
//sc O(1)

//optimal(dutch national flag algo)
//sc O(1)
//tc O(n) 

