#include<bits/stdc++.h>
using namespace std;

void func(int ind, int sum, vector<int> & arr, int N, vector<int> &sumSubSet) {
    if(ind == N){
        sumSubSet.push_back(sum);
        return;
    }
    func(ind+1, sum+arr[ind], arr, N, sumSubSet);

    func(ind+1, sum, arr, N, sumSubSet);
}

vector<int> subSetSums(vector<int> &arr, int N) {
    vector<int> sumSubSet;
    func(0, 0, arr, N, sumSubSet);
    sort(sumSubSet.begin(), sumSubSet.end());
    return sumSubSet;
}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main(){
    init_code();
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];

    vector<int> ans = subSetSums(arr, num);

    for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";

}