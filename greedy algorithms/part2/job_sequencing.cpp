#include <bits/stdc++.h>
using namespace std;

struct job{
    int id;
    int dead;
    int profit;
};

bool comp(job a, job b){
    return (a.profit > b.profit);
}

pair<int, int> jobschedule(job arr[], int n){
    sort(arr, arr+n, comp);
    int maxi = arr[0].dead;
    for(int i=1; i<n; i++){
        maxi = max(maxi, arr[i].dead);
    }
    vector<int> slot(maxi + 1, -1);
    int cntJobs=0, jobProfit=0;
    for(int i=0; i<n; i++){
        for(int j=arr[i].dead; j>0; j--){
            if(slot[j]==-1){
                slot[j] = arr[i].id;
                cntJobs++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }
    return make_pair(cntJobs, jobProfit);
}

void init_code() {
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main() {
    init_code();
    int n;
    cin >> n;
    vector<job> jobs(n);
    for (int i = 0; i < n; i++) {
        int id, dead, profit;
        cin >> id >> dead >> profit;
        jobs[i] = {id, dead, profit};
    }
    pair<int, int> result = jobschedule(jobs.data(), n);
    cout << "Maximum number of jobs: " << result.first << endl;
    cout << "Maximum profit: " << result.second << endl;
}