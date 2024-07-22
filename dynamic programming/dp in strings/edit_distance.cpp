#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int editDistance(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    vector<int> prev(m+1, 0), cur(m+1, 0);
    for(int j=0; j<=m; j++) prev[j] = j;

    for(int i=1; i<=n; i++){
        cur[0] = i;
        for(int j=1; j<=m; j++){
            if(str1[i-1] == str2[j-1]){
                cur[j] = prev[j-1];
            } else{
                cur[j] = 1 + min(prev[j], min(cur[j-1], prev[j-1]));
            }
        }
        prev = cur;
    }
    return prev[m];
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
    
    int result = editDistance(s, t);
    cout << result << endl;
    
    return 0;
}