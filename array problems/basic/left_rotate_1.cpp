#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> rotateArr(vector<int> &a, int n){
    int temp = a[0];
    for(int i=1; i<n; i++){
        a[i-1] = a[i];    
    }
    a[n-1] = temp;
    return a;
}

int main(){
    init_code();
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    rotateArr(arr, num);
    for(int i=0; i<num; i++) cout << arr[i] << " ";
    return 0;
}

//the extra space used is O(1) and the net space used is O(n)