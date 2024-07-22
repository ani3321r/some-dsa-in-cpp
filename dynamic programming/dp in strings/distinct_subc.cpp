#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int numDist(string s, string t) {
    int n = s.size();
    int m = t.size();
    vector<double> prev(m+1, 0);
    prev[0] = 1;
    for(int i=1; i<=n; i++){
        for(int j=m; j>=1; j--){
            if(s[i-1] == t[j-1]){
                prev[j] = prev[j-1] + prev[j];
            }
        }
    }
    return (int)prev[m];
}

void init_code() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
}

int main() {
    init_code();
    string s, t;
    cin >> s >> t;
    
    int result = numDist(s, t);
    cout << result << endl;
    
    return 0;
}