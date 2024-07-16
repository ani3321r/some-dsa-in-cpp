#include <iostream>
#include <vector>
using namespace std;

bool subsetSumK(int n, int k, vector<int> &arr){
    vector<bool> prev(k+1, 0), cur(k+1, 0);
    prev[0] = cur[0] = true;
    prev[arr[0]] = true;
    for(int ind=1; ind<n; ind++){
        for(int target=1; target<=k; target++){
            bool notTake = prev[target];
            bool take = false;
            if(arr[ind] <= target) take = prev[target-arr[ind]];
            cur[target] = take | notTake;
        }
        prev = cur;
    }
    return prev[k];
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    int n, k;
    cin >> n >> k;
    vector<int> mat(n);
    for(int i = 0; i < n; i++) cin >> mat[i];
    string res = (subsetSumK(n, k, mat) == true) ? "true" : "false";
    cout << res << endl;
    return 0;
}