#include<bits/stdc++.h>
using namespace std;

void swapIfGreater(long long a1[], long long a2[], int i1, int i2){
    if(a1[i1] > a2[i2]){
        swap(a1[i1], a2[i2]);
    }
}

void mergeArr(long long a1[], long long a2[], int n, int m){
   int len = (n+m);
   int gap = (len/2) + (len%2);
   while(gap > 0){
        int left = 0;
        int right = left + gap;
        while(right < len){
            if(left<n && right >= n){
                swapIfGreater(a1, a2, left, right-n);
            }else if(left >= n){
                swapIfGreater(a2, a2, left-n, right-n);
            }else{
                swapIfGreater(a1, a1, left, right);
            }
            left++, right++;
        }
        if(gap == 1) break;
        gap = (gap/2) + (gap%2);
   }
}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main(){
    init_code();
    int n, m;
    cin >> n;
    cin >> m;
    long long arr1[n];
    long long arr2[m];
    for(int i=0; i<n; i++) cin >> arr1[i];    
    for(int i=0; i<m; i++) cin >> arr2[i]; 
    mergeArr(arr1, arr2, n, m);
    for(int i=0; i<n; i++) cout << arr1[i] << " "; 
    for(int i=0; i<m-1; i++) cout << arr2[i] << " "; 
    return 0;
}


//brute 
//sc O(n+m)
//tc 2*O(n+m)

/*
void mergeArr(vector<int> &a1, vector<int> &a2, int n, int m){
    vector<int> a3[n+m];
    int left = 0;
    int right = 0;
    int index = 0;
    while(left<n && right<m){
        if(a1[left] <= a2[right]){
            a3[index] = a1[left];
            left++, index++;
        }else{
            a3[index] = a2[right];
            right++, index++;
        }
    }
    while(left<n){
        a3[index++] = a1[left++];
    }
    while(right<m){
        a3[index++] = a2[right++];
    }
    for(int i=0; i<n+m; i++){
        if(i<n) a1[i] = a3[i];
        else a2[i-n] = a3[i];
    }
}
*/


//optimal 1
//sc O(1)
//tc O(min(n,m)) + O(nlog(n)) + O(mlog(m))

/*
void mergeArr(vector<int> &a1, vector<int> &a2, int n, int m){
    int left = n-1;
    int right = 0;
    while(left >= 0 && right < m){
        if(a1[left] > a2[right]){
            swap(a1[left], a2[right]);
            left--, right++;
        }else{
            break;
        }
    }
    sort(a1, a1+n);
    sort(a2, a2+m);
}
*/

//optimal 2 (gap method)
//sc O(1)
//tc log(n+m) * O(n+m) (here log is base 2 as gap is decreasing by a factor of 2)