#include <iostream>
#include <vector>
using namespace std;

long maxProfit(vector<long> &values, int n){
    long aheadNotBuy, aheadBuy, curBuy, curNotBuy;
    aheadNotBuy = aheadBuy = 0;
    for(int ind=n-1; ind>=0; ind--){
        curNotBuy = max(values[ind] + aheadBuy, 0 + aheadNotBuy);
        curBuy = max(-values[ind]+aheadNotBuy, 0+aheadBuy);
        aheadBuy = curBuy;
        aheadNotBuy = curNotBuy;
    }
    return aheadBuy;
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
    vector<long> prices(s);
    for(int i=0; i<s; i++) cin >> prices[i];
    
    long result = maxProfit(prices, s);
    cout << result << endl;
    
    return 0;
}