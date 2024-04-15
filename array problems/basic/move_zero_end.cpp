#include<bits/stdc++.h>
using namespace std;

vector<int>moveZeros(vector<int> &a, int n ){
    int j = -1;
    for(int i=0; i<n; i++){
        if(a[i]==0){
            j=i;
            break;
        }
    }
    if(j == -1) return a;

    for(int i=j+1; i<n; i++){
        if(a[i] != 0){
            swap(a[i], a[j]);
            j++;
        }
    }
    return a;
}

int main(){
    init_code();
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    int d;
    cin >> d;    
    moveZeros(arr, num);
    for(int i=0; i<num; i++) cout << arr[i] << " ";
    return 0;
}
//brute force
//the extra space used is O(x), worst case O(n)
//tc O(2n)
/*
vector<int> moveZero(vector<int>a, int n){
    vector<int>temp;
    for(int i=0; i<n; i++){
        if(a[i] != 0){
            temp.push_back(a[i]);
        }
    }

    int nz = temp.size();
    for(int i=0; i<nz; i++){
        a[i] = temp[i];
    }

    for(int i=nz; i<n; i++){
        a[i] = 0;
    }
    return a;
}

*/

//optimal case
//sc O(1) extra space not required
//tc O(n)

