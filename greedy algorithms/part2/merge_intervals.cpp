#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals){
    vector<vector<int>> ans;
    if(intervals.size() == 0){
        return ans;
    }
    sort(intervals.begin(), intervals.end());
    vector<int> tempInt = intervals[0];
    for(auto it : intervals){
        if(it[0] <= tempInt[1]){
            tempInt[1] = max(it[1], tempInt[1]);
        } else{
            ans.push_back(tempInt);
            tempInt = it;
        }
    }
    ans.push_back(tempInt);
    return ans;
}

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main(){
    init_code();
    int n;
    cin >> n;
    vector<vector<int>> intervals(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }
    vector<vector<int>> merged = merge(intervals);
    cout << "Merged Intervals:" << endl;
    for (const auto& interval : merged) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
    return 0;
}