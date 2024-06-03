#include<bits/stdc++.h>
using namespace std;

int maxFruits(vector<int> &nums) {
    int l = 0, r = 0, maxFruit = 0;
    map<int, int> mpp;
    while (r < nums.size()) {
        mpp[nums[r]]++;
        if (mpp.size() > 2) {
            while (mpp.size() > 2) {
                mpp[nums[l]]--;
                if (mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
        }
        if (mpp.size() <= 2) {
            maxFruit = max(maxFruit, r - l + 1);
        }
        r++;
    }
    return maxFruit;
}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}    

int main(){
    init_code();
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    cout << maxFruits(nums) << endl;
}

//more optimised code
//tc O(n)
//sc O(1)
/*
int maxFruits(vector<int> &nums) {
    int l = 0, r = 0, maxFruit = 0;
    map<int, int> mpp;
    while (r < nums.size()) {
        mpp[nums[r]]++;
        if (mpp.size() > 2) {
            mpp[nums[l]]--;  
            if (mpp[nums[l]] == 0) mpp.erase(nums[l]);
            l++;
        }
        if (mpp.size() <= 2) {
            maxFruit = max(maxFruit, r - l + 1);
        }
        r++;
    }
    return maxFruit;
}
*/