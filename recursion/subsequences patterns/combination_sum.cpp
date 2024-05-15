#include<bits/stdc++.h>
using namespace std;

void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
    if(ind == arr.size()){
        if(target == 0){
            ans.push_back(ds);
        }
        return;
    }
    if(arr[ind] <= target){
        ds.push_back(arr[ind]);
        findCombination(ind, target-arr[ind], arr, ans, ds);
        ds.pop_back();
    }
    findCombination(ind+1, target, arr, ans, ds);
}

vector<vector<int>> combinationSum(vector<int> &arr, int target){
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, arr, ans, ds);
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
    int num, target;
    cin >> num;
    cin >> target;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];

    vector<vector<int>> ans = combinationSum(arr, target);

    cout << "all the possible combinations are:\n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
}