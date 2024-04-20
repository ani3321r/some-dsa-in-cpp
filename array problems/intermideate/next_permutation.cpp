#include<bits/stdc++.h>
using namespace std;

vector<int> nextPerm(vector<int> &a, int n){
    int ind = -1;
    for(int i=n-2; i>=0; i--){
        if(a[i]<a[i+1]){
            ind = i;
            break;
        }
    }
    if(ind == -1){
        reverse(a.begin(), a.end());
        return a;
    }
    for(int i=n-1; i>ind; i--){
        if(a[i]>a[ind]){
            swap(a[i], a[ind]);
            break;
        }
    }
    reverse(a.begin()+ind+1, a.end());
    return a;
}

int main(){
    init_code();
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    vector<int> arr2 = nextPerm(arr, num);
    for(int i=0; i<num; i++) cout << arr2[i] << " ";
    return 0;
}
//brute force
//tc(n! * n)

//for better solution in this case we can use a stl next_permutation

//optimal
//sc O(1)
//tc O(3n) 

