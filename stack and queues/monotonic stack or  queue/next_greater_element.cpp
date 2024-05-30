#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> map; 
    stack<int> st;
    for (int num : nums2) {
        while (!st.empty() && st.top() < num){ 
            map[st.top()] = num;
            st.pop();
        }
        st.push(num); 
    }   
    for (int i = 0; i < nums1.size(); i++){ 
        nums1[i] = map.count(nums1[i]) ? map[nums1[i]] : -1; 
    }
    return nums1;
}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main(){
    int n1, n2;
    cin >> n1;
    cin >> n2;
    vector<int> arr1(n1), arr2(n2);
    for(int i=0; i<n1; i++) cin >> arr1[i];
    for(int i=0; i<n2; i++) cin >> arr2[i];
    vector<int> arr3 = nextGreaterElement(arr1, arr2);
    for(int i=0; i<arr3.size(); i++) cout << arr3[i];
}