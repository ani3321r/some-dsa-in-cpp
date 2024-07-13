#include <iostream>
#include <vector>
using namespace std;

int maxAdj(vector<int> &nums) {
    int n = nums.size();
    int prev = nums[0];
    int prev2 = 0;
    for(int i=1; i<n; i++){
        int take = nums[i];
        if(i > 1) take += prev2;
        int notTake = 0 + prev;
        int curi = max(take, notTake);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    int ans = maxAdj(nums);
    cout << ans << endl;
    return 0;
}