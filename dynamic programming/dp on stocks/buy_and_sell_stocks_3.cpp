#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices, int n){
    vector<vector<int>> after(2, vector<int>(3, 0));
    vector<vector<int>> cur(2, vector<int>(3, 0));
    for(int ind=n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            for(int cap=1; cap<=2; cap++){
                if(buy==1){
                    cur[buy][cap] = max(-prices[ind]+after[0][cap], 0+after[1][cap]);
                }
                else{
                    cur[buy][cap] = max(prices[ind]+after[1][cap-1], 0+after[0][cap]);
                }
            }
        }
        after = cur;
    }
    return after[1][2];
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
    
    int result = maxProfit(prices, s);
    cout << result << endl;
    
    return 0;
}