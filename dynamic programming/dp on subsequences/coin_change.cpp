#include <iostream>
#include <vector>
using namespace std;

long WaysToChange(vector<int> a, int n, int val) {
    vector<int> prev(val+1, 0), cur(val+1, 0);
    for(int T=0; T<=val; T++){
        prev[T] = (T%a[0] == 0);
    }
    for(int ind=1; ind<n; ind++){
        for(int T=0; T<=val; T++){
            long notTake = prev[T];
            long take = 0;
            if(a[ind]<=T) take = cur[T-a[ind]];
            cur[T] = take + notTake;
        }
        prev = cur;
    }
    return prev[val];
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
    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    
    long res = WaysToChange(arr, n, k);
    cout << res << endl;
    
    return 0;
}