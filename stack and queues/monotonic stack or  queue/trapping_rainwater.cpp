#include<bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();
    int left = 0, right = n-1;
    int res = 0;
    int maxLeft = 0;
    int maxRight = 0;
    while(left <= right){
        if(height[left] <= height[right]){
            if(height[left] > maxLeft) maxLeft = height[left];
            else res += maxLeft - height[left];
            left++;
        }
        else{
            if(height[right] > maxRight) maxRight = height[right];
            else res += maxRight - height[right];
            right--;
        }
    }
    return res;
}    

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main(){
    init_code();
    int n;
    cin >> n;
    vector<int> height(n);
    for(int i=0; i<n; i++) cin >> height[i];
    cout << trap(height);
}