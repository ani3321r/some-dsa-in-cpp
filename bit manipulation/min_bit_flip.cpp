#include<iostream>
using namespace std;

int minBitFlips(int start, int goal) {
        int res=start^goal;
        int count=0;
        while(res){
            count+=res&1; 
            res>>=1; 
        }
        return count;
}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main(){
    init_code();
    int start, target;
    cin >> start;
    cin >> target;
    cout << minBitFlips(start, target);
}