#include <bits/stdc++.h>
using namespace std;

int wordLadderLength(string startWord, string targetWord, vector<string> wordList){
    queue<pair<string, int>> q;
    q.push({startWord, 1});
    unordered_set st(wordList.begin(), wordList.end());
    st.erase(startWord);
    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if(word == targetWord) return steps;
        for(int i=0; i<word.size(); i++){
            char original = word[i];
            for(char ch='a';  ch<='z'; ch++){
                word[i] = ch;
                if(st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word, steps+1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
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
    cin >> n;
    vector<string> wordlist(n);
    cin >> start >> end;
    for(int i=0; i<n; i++) cin >> wordlist[i];
    
    cout << wordLadderLength(start, end, wordlist);
    return 0;
}