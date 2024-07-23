#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices, int n, int k){
    vector<vector<int>> after(2, vector<int>(k+1, 0));
    vector<vector<int>> cur(2, vector<int>(k+1, 0));
    for(int ind=n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            for(int cap=1; cap<=k; cap++){
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
    return after[1][k];
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    int s, k;
    cin >> s >> k;
    vector<int> prices(s);
    for(int i=0; i<s; i++) cin >> prices[i];
    
    int result = maxProfit(prices, s, k);
    cout << result << endl;
    
    return 0;
}


//lower tc
//same for buy sell stock 3
// int maxProfit(vector<int> &prices, int n, int k){
//     vector<int> after(2*k+1, 0);
//     vector<int> cur(2*k+1, 0);
//     for(int ind=n-1; ind>=0; ind--){
//         for(int tranNo=2*k-1; tranNo>=0; tranNo--){
//             if(tranNo%2==0){
//                 cur[tranNo] = max(-prices[ind]+ after[tranNo+1], 0+after[tranNo]);
//             }
//             else{
//                 cur[tranNo] = max(prices[ind]+ after[tranNo+1], 0+after[tranNo]);
//             }
//         }
//         after = cur;
//     }
//     return after[0];
// }