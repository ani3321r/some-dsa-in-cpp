#include<bits/stdc++.h>
using namespace std;

vector<int> UniSortedArr(vector<int> &a, vector<int> &b){
    int n1 = a.size();
    int n2 = b.size();
    int i = 0;
    int j = 0;
    vector<int> unionArr;
    while(i<n1 && j<n2){
        if(a[i] <= b[j]){
            if(unionArr.size() == 0 || unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else{
            if(unionArr.size() == 0 || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    while(j<n2){
        if(unionArr.size() == 0 || unionArr.back() != b[j]){
                unionArr.push_back(b[j]);
        }
        j++;
    }
    while(i<n1){
        if(unionArr.size() == 0 || unionArr.back() != a[i]){
                unionArr.push_back(a[i]);
        }
        i++;
    }
    return unionArr;
}

int main(){
    init_code();
    int num;
    cin >> num;
    vector<int> arr1(num);
    for(int i=0; i<num; i++) cin >> arr1[i];
    vector<int> arr2(num);
    for(int i=0; i<num; i++) cin >> arr2[i]; 
    vector<int> arr3 = UniSortedArr(arr1, arr2);
    for(int i=0; i<num*2; i++) cout << arr3[i] << " ";
    return 0;
}
//brute force
//the extra space used is O(n1+n2)+O(n1+n2)
//tc O(n1 log(n) + n2 log(n)) + O(n1+n2)
/*
vector<int> sortedArr(vector<int>a, vector<int> b){
    int n1 = a.size();
    int n2 = b.size();
    set<int> st;
    for(int i=0; i<n1; i++){
        st.insert(a[i]);
    }
    for(int i=0; i<n2; i++){
        st.insert(b[i]);
    }
    vector<int> temp;
    for(auto it: st){
        temp.push_back(it);
    }
    return temp;
}

*/

//optimal case
//sc O(n1 + n2) 
//tc O(n1 + n2) 

