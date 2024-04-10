#include<bits/stdc++.h>
using namespace std;

int main(){
    //this is for the array input
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    //precompute
    int hash[13] = {0};//we are taking 13 as we are expecting a maximum of 12 here
    for(int i=0; i<n; i++){
        hash[arr[i]] += 1;
    }

    //this is the input for fetching the data
    int q;
    cin >> q;
    while(q--){
        int num; 
        cin >> num;
        cout << hash[num] << endl;
    }

    return 0;
}// when we using hash we can go upto 10^6 inside main and 10^7 globally