#include<bits/stdc++.h>
using namespace std;

int subStrWithKdisChar(string str, int k){
    int maxLen=0, l=0, r=0;
    map<char, int> mpp;
    while(r < str.size()){
        mpp[str[r]]++;
        if(mpp.size() > k){
            mpp[str[l]]--;
            if(mpp[str[l]] == 0) mpp.erase(mpp[str[l]]);
            l = l + 1;
        }
        if(mpp.size() <= k) maxLen = max(maxLen, r-l+1);
        r = r + 1;
    }
    return maxLen;
}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}    

int main(){
    init_code();
    string str;
    int k;
    cin >> str;
    cin >> k;
    cout << subStrWithKdisChar(str, k) << endl;
}