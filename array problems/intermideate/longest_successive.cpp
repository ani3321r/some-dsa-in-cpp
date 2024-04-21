#include<bits/stdc++.h>
using namespace std;

int longestSuccElements(vector<int> &a, int n){
    if(n == 0) return 0;
    int longest = 1;
    unordered_set<int> st;
    for(int i=0; i<n; i++){
        st.insert(a[i]);
    }

    for(auto it: st){
        if(st.find(it-1) == st.end()){
            int cnt = 1;
            int x = it;
            while(st.find(x+1) != st.end()){
                x += 1;
                cnt += 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}

int main(){
    init_code();
    int num;
    cin >> num;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << longestSuccElements(arr, num);    
    return 0;
}
//brute force
//sc(1)
//tc(n^2)

//better
//sc(1)
//tc O(n) + O(nlog(n))

/*
int longestSuccElements(vector<int> &a, int n){
    if(n == 0) return 0;
    sort(a.begin(), a.end());
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;
    for(int i=0; i<n; i++){
        if(a[i]-1 == lastSmaller){
            cnt += 1;
            lastSmaller = a[i];
        }
        else if(lastSmaller != a[i]){
            cnt = 1;
            lastSmaller = a[i];
        }
        longest = max(longest, cnt);
    }       
    return longest;
}
*/

//optimal
//sc O(n)
//tc O(3n)