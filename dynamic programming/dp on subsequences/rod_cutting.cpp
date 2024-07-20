#include <iostream>
#include <vector>
using namespace std;

int rodCut(vector<int> &prices, int n) {
    vector<int> prev(n+1, 0), cur(n+1, 0);
    for(int N=0; N<=n; N++){
        prev[N] = N*prices[0];
    }
    for(int ind=1; ind<n; ind++){
        for(int N=0; N<=n; N++){
            int notTake = 0 + prev[N];
            int take = INT_MIN;
            int rodLength = ind+1;
            if(rodLength <= N){
                take = prices[ind] + cur[N-rodLength];
            }
            cur[N] = max(take, notTake);
        }
        prev = cur;
    }
    return prev[n];
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
    vector<int> arr1(n);
    for(int i = 0; i < n; i++) cin >> arr1[i];
    
    int res = rodCut(arr1, n);
    cout << res << endl;
    
    return 0;
}