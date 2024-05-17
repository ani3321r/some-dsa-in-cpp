#include<bits/stdc++.h>
using namespace std;

void func(vector<int> &nums, int index, vector<int> &ds, set<vector<int>> &res) {
     if (index == nums.size()) {
        sort(ds.begin(), ds.end());
        res.insert(ds);
        return;
      }
      ds.push_back(nums[index]);
      func(nums, index + 1, ds, res);
      ds.pop_back();
      func(nums, index + 1, ds, res);
}

vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    vector < vector < int >> ans;
    set < vector < int >> res;
    vector < int > ds;
    func(nums, 0, ds, res);
    for (auto it = res.begin(); it != res.end(); it++) {
      ans.push_back( * it);
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
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];

    vector<vector<int>> ans = subsetsWithDup(arr);

    cout << "all the possible subsets are:\n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
}