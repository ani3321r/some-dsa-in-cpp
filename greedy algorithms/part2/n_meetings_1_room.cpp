#include <bits/stdc++.h>
using namespace std;

struct meeting {
    int start;
    int end;
    int pos;
};

bool comp(struct meeting m1, meeting m2){
    if(m1.end < m2.end) return true;
    else if(m1.end > m2.end) return false;
    else if(m1.pos < m2.pos) return true;
    return false;
}

vector<int> maxMeeting(int s[], int e[], int n){
    struct meeting meet[n];
    for(int i=0; i<n; i++){
        meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i+1;
    }
    sort(meet, meet+n, comp);
    vector<int> ans;
    int limit = meet[0].end;
    ans.push_back(meet[0].pos);
    for(int i=1; i<n; i++){
        if(meet[i].start > limit){
            limit = meet[i].end;
            ans.push_back(meet[i].pos);
        }
    }
    return ans;
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
    vector<int> start(n), end(n);
    for (int i = 0; i < n; i++){
        cin >> start[i];
    }
    for (int i = 0; i < n; i++){
        cin >> end[i];
    }
    vector<int> result = maxMeeting(start.data(), end.data(), n);
    cout << "Maximum meetings that can be attended: " << result.size() << endl;
    cout << "Meetings attended (in order): ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}