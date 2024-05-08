#include<bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &arr, int pages){
    int students=1;
    long long pagesStudent=0;
    for(int i=0; i<arr.size(); i++){
        if(pagesStudent + arr[i] <= pages){
            pagesStudent += arr[i];
        } else{
            students += 1;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int> &arr, int n, int m){
    if(m>n) return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while(low<=high){
        int mid = (low+high)/2;
        int students = countStudents(arr, mid);
        if(students > m){
            low = mid + 1;
        } else{
            high = mid - 1; 
        }
    }
    return low;
}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main(){
    init_code();
    int num, d;
    cin >> num;
    cin >> d;
    vector<int> arr(num);
    for(int i=0; i<num; i++) cin >> arr[i];
    cout << findPages(arr, num, d);
    return 0;
}