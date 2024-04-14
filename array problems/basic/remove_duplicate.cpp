#include<bits/stdc++.h>
#include<vector>
using namespace std;

int removeDuplicate(vector<int> &a, int n){
    int i=0;
    for(int j=1; j<n; j++){
        if(a[i]!=a[j]){
            a[i+1] = a[j];
            i++;
        }
    }
    return i+1;
}

int main(){
    init_code();
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << removeDuplicate(arr, num) << endl;
    for(int i=0; i<num; i++) cout << arr[i] << " ";
    return 0;
}

//time complexity nlog(n)+O(n)
//space complexity O(n) 
//we use two pointer approach to get a optimal solution
//O(n) tc
//O(1) sc