#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &a, int n, int target){
    vector<vector<int>> ans;
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++){
        if(i>0 && a[i] == a[i-1]) continue;
        for(int j=i+1; j<n; j++){
            if(j != i+1 && a[j] == a[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k<l){
                long long sum = a[i];
                sum += a[j];
                sum += a[k];
                sum += a[l];
                if(sum == target){
                    vector<int> temp = {a[i], a[j], a[k], a[l]};
                    ans.push_back(temp);
                    k++, l--;
                    while(k<l && a[k] == a[k-1]) k++;
                    while(k<l && a[l] == a[l+1]) l--;
                } 
                else if(sum<target) k++;
                else l--;
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
    int num, target;
    cin >> num;
    cin >> target;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];

    vector<vector<int>> ans = fourSum(arr, num, target);
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
//sc 2*O(no. of quads)
//tc O(n^4) 

/*
vector<vector<int>> fourSum(vector<int> &a, int n, int target){
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                for(int l=k+1; l<n; l++){
                    long long sum = a[i] + a[j];//if all the four written in the same line the integer limit might have crossed
                    sum += a[k];
                    sum += a[l];
                    if(sum == target){
                        vector<int> temp = {a[i], a[j], a[k], a[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
*/

//better
//sc O(n) + O(quads)*2
//tc O(n^3 * log(m))

/*
vector<vector<int>> fourSum(vector<int> &a, int n){
    set<vector<int>> st;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            set<long long> hashset;
            for(int k=j+1; k<n; k++){
                long long sum = a[i] + a[j];
                sum += a[k];
                long long fourth = target - (sum);
                if(hashset.find(fourth) != hashset.end()){
                    vector<int> temp = {a[i], a[j], a[k], (int)(target)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(a[k]);
            }
        }
    }        
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}
*/

//optimal
//sc O(no. of quads)
//tc O(n^3) 