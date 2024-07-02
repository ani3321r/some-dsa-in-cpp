#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> q;
    q.push({startWord});
    unordered_set<string> usedOnLevel;
    int level = 0;
    vector<vector<string>> ans;
    
    while(!q.empty()) {
        int size = q.size();
        usedOnLevel.clear();
        
        while(size--) {
            auto vec = q.front();
            q.pop();
            string word = vec.back();
            
            if(word == targetWord) {
                if(ans.empty() || ans[0].size() == vec.size()) {
                    ans.push_back(vec);
                }
                continue;
            }
            
            if(!ans.empty() && vec.size() >= ans[0].size()) continue;
            
            for(int i=0; i<word.size(); i++) {
                char original = word[i];
                for(char c='a'; c<='z'; c++) {
                    word[i] = c;
                    if(st.count(word) > 0) {
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.insert(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        
        for(auto it: usedOnLevel) {
            st.erase(it);
        }
        level++;
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
    string start, end;
    int n;
    cin >> start >> end >> n;
    vector<string> wordlist(n);
    for(int i=0; i<n; i++) cin >> wordlist[i];
    
    vector<vector<string>> ans = wordLadderLength(start, end, wordlist);
    
    if(ans.empty()) {
        cout << "No solution found" << endl;
    } else {
        for (const auto& path : ans) {
            for (const auto& word : path) {
                cout << word << " ";
            }
            cout << endl;
        }
    }
    return 0;
}