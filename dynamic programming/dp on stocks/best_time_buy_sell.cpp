#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxiProfit(vector<int> &prices) {
    int mini = prices[0];
    int maxProfit = 0;
    int n = prices.size();
    for(int i=0; i<n; i++){
        int cost = prices[i] - mini;
        maxProfit = max(maxProfit, cost);
        mini = min(mini, prices[i]); 
    }
    return maxProfit;
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
    vector<int> prices(s);
    for(int i=0; i<s; i++) cin >> prices[i];
    
    int result = maxiProfit(prices);
    cout << result << endl;
    
    return 0;
}