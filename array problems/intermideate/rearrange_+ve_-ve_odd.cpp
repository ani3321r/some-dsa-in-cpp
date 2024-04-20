#include<bits/stdc++.h>
using namespace std;

vector<int> rearrange(vector<int> &a, int n){
    vector<int> pos, neg;
    for(int i=0; i<n; i++){
        if(a[i] > 0) pos.push_back(a[i]);
        else neg.push_back(a[i]);
    }
    if(pos.size() > neg.size()){
        for(int i=0; i<neg.size(); i++){
            a[2*i] = pos[i];
            a[2*i + 1] = neg[i];
        }
        int index = neg.size()*2;
        for(int i=neg.size(); i<pos.size(); i++){
            a[index] = pos[i]; 
            index++;
        }
    }
    else{
        for(int i=0; i<pos.size(); i++){
            a[2*i] = pos[i];
            a[2*i + 1] = neg[i];
        }
        int index = pos.size()*2;
        for(int i=pos.size(); i<neg.size(); i++){
            a[index] = neg[i]; 
            index++;
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
    vector<int> arr2 = rearrange(arr, num);
    for(int i=0; i<num; i++) cout << arr2[i] << " ";
    return 0;
}

//optimal
//sc O(n)
//tc O(2n) 

