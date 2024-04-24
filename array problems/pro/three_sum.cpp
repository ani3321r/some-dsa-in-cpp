#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> triplet(vector<int> &a, int n){
    vector<vector<int>> ans;
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++){
        if(i>0 && a[i] == a[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j<k){
            int sum = a[i] + a[j] + a[k];
            if(sum<0){
                j++;
            } else if(sum>0){
                k--;
            } else {
                vector<int> temp = {a[i] , a[j] , a[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && a[j] == a[j-1]) j++;
                while(j<k && a[k] == a[k+1]) k++;
            }
        }
    }
    return ans;
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

    vector<vector<int>> ans = triplet(arr, num);
    cout << "The required sets are: \n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}


//brute 
//sc 2*O(no. of triplets)
//tc O(n^3) + O(log(no of triplets))

/*
vector<vector<int>> triplet(vector<int> &a, int n){
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(a[i] + a[j] + a[k] == 0){
                vector<int> temp = {a[i], a[j], a[k]};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
*/

//better
//sc O(n) + O(no. of triplets)
//tc O(n^2 * log(m))

/*
vector<vector<int>> triplet(vector<int> &a, int n){
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        set<int> hashset;
        for(int j=i+1; j<n; j++){
            int third = -(a[i] + a[j]);
            if(hashset.find(third) != hashset.end()){
                vector<int> temp = {a[i] + a[j] + third}
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(a[j]);
        }    
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
*/

//optimal
//sc O(no. of triplets)
//tc O(nlog(n)) + O(n)

