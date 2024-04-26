#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlaping(vector<vector<int>> &a){
    int n = a.size();
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        if(ans.empty() || a[i][0] > ans.back()[1]){
            ans.push_back(a[i]);
        } else{
            ans.back()[1] = max(ans.back()[1], a[i][1]);
        }
    }
    return ans;
}

int main(){
    vector<vector<int>> arr = {{1,3},{2,4},{3,5},{6,7}}; 
    vector<vector<int>> ans = mergeOverlaping(arr);
    cout << "The required sets are: \n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}


//brute 
//sc O(n)
//tc O(nlog(n)) + O(2n) 

/*
vector<vector<int>> mergeOverlaping(vector<vector<int>> &a, int n){
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        int start = a[i][0];
        int end = a[i][1];
        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }
        for(int j=i+1; j<n; j++){
            if(a[j][0] <= end){
                end = max(end, arr[j][1]);
            }else{
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}
*/

//optimal
//sc O(n)
//tc O(nlog(n)) + O(n)

