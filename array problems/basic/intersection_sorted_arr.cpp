#include<bits/stdc++.h>
using namespace std;

vector<int> arrIntersect(vector<int> &a, vector<int> &b, int n, int m){
    int i = 0;
    int j = 0;
    vector<int> ans;
    while(i<n && j<m){
        if(a[i] < b[j]){
            i++;
        }
        else if(b[j] < a[i]){
            j++;
        }
        else{
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans; 
}

int main(){
    init_code();
    int num1;
    cin >> num1;
    int num2;
    cin >> num2;
    vector<int> arr1(num1);
    for(int i=0; i<num1; i++) cin >> arr1[i];
    vector<int> arr2(num2);
    for(int i=0; i<num2; i++) cin >> arr2[i]; 
    vector<int> arr3 = arrIntersect(arr1, arr2, num1, num2);
    for(int i=0; i<num1; i++) cout << arr3[i] << " ";
    return 0;
}
//brute force
//the extra space used is O(n2)
//tc O(n1 * n2)
/*
vector<int> arrIntersect(vector<int> &a, int n, vector<int> &b, int m){
    vector<int> ans;
    int vis[m] = {0};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i] == b[j] && vis[j] == 0){
                ans.push_back(a[i]);
                vis[j] = 1;
                break;
            }
            if(b[j] > a[i]) break;
        }
    }
    return ans;
}

*/

//optimal case
//sc O(1) 
//tc O(n1 + n2) 

