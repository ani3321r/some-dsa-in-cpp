#include<bits/stdc++.h>
using namespace std;

vector<int> genRow(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for(int col=1; col<row; col++){
        ans = ans*(row-col);
        ans = ans / (col);
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n){
    vector<vector<int>> ans;
    for(int i=1; i<=n; i++){
        ans.push_back(genRow(i));
    }
    return ans;
}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main(){
    init_code();
    int num;
    cin >> num;
    vector<vector<int>> ans = pascalTriangle(num);

    cout << "The pascal triangle is: \n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }

    return 0;
}


//optimal(element acc to position)
//sc O(1)
//tc O(r)
/*
int nCr(int n, int r){
    long long res = 1;
    for(int i=0; i<r; i++){
        res = res*(n-i);
        res = res/(i+1);;
    }
    return res;
}

when running in the main func we have to give nCr(r-1, c-1)
here r is row and c is column given 
*/

//brute(print the given row)
//sc O(1)
//tc O(n*r)
/*
for(c=1; c<=n; c++){
    cout << nCr(n-1, c-1);
}

n is the row
*/

//optimal(print the given row)
//sc O(1)
//tc O(n)
/*
int ans=1;
cout << ans;
for(i=1; i<n; i++){
    ans = ans * (n-i);
    ans = ans/i;
    cout << ans;
}

n is the number of rows
*/

//brute(whole triangle)
//sc O(1)
//tc O(n^3)
/*
vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;
    for (int row = 1; row <= n; row++) {
        vector<int> tempLst; // temporary list
        for (int col = 1; col <= row; col++) {
            tempLst.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}
*/

//optimal(whole triangle)
//sc O(1)
//tc O(n^2)