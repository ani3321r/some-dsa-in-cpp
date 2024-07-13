#include <iostream>
#include <vector>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points){
    vector<int> dp(4, 0);

    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for(int day=1; day<n; day++){
        vector<int> temp(4, 0);
        for(int last=0; last<4; last++){
            for(int task=0; task<3; task++){
                if(task != last){
                    int point = points[day][task] + dp[task];
                    temp[last] = max(temp[last], point);
                }
            }
        }
        dp = temp;
    }
    return dp[3];
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
    vector<vector<int>> points(n, vector<int>(3));
    for(int i = 0; i < n; i++){
        cin >> points[i][0] >> points[i][1] >> points[i][2];
    }
    int ans = ninjaTraining(n, points);
    cout << ans << endl;
    return 0;
}