#include<bits/stdc++.h>
using namespace std;

string read(vector<int> &a, int n, int target){
    int left = 0, right = n-1;
    sort(a.begin(), a.end());
    while(left<right){
        int sum = a[left] + a[right];
        if(sum == target){
            return "yes";
        } 
        else if(sum < target) left++;
        else right--;
    }
    return "no";
}

int main(){
    init_code();
    int num;
    cin >> num;
    int target;
    cin >> target;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << read(arr, num, target);    
    return 0;
}
//brute force
//sc O(1)
//tc O(n^2)

//better (boolean)
//tc O(nlog(n))
//sc O(n)
/*
string read(vector<int> book, int n, int target){
    map<int, int> mpp;
    for(int i=0; i<n; i++){
        int a = book[i];
        int more = target - a;
        if(mpp.find(more) != mpp.end()){
            return "yes";
        }
        mpp[a] = i;
    }
    return "no";
}
*/
//better (indexes)
/*
vector<int> twoSum(vector<int> &nums, int target){
    map<int, int> mpp;
    int n = nums.size();
    for(int i=0; i<n; i++){
        int num = nums[i];
        int  moreNeeded = target - num;
        if(mpp.find(moreNeeded) != mpp.end()){
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return {-1, -1};
}
*/

//optimal
//sc O(1)
//tc O(n) + O(nlog(n))

//here the optimal solution i.e., not using map is only better for
//returning boolean two sum problem if we use optimal for finding
//indexes it will take a lot of extra space so the better solution
//is optimised for the second variant if twosum
