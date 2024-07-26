#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int lengthOfLIS(vector<int>& nums, int n) {
    vector<int> temp;
    temp.push_back(nums[0]);
    int len = 1;
    for(int i=0; i<n; i++){
        if(nums[i] > temp.back()){
            temp.push_back(nums[i]);
            len++;
        }
        else{
            int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
            temp[ind] = nums[i];
        }
    }
    return len;
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    int s;
    cin >> s;
    vector<int> arr(s);
    for(int i=0; i<s; i++) cin >> arr[i];
    
    long result = lengthOfLIS(arr, s);
    cout << result << endl;
    
    return 0;
}