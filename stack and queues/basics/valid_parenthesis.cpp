#include<bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    stack<char> st; 
    for (char c : s) { 
        if (c == '(' || c == '{' || c == '[') { 
            st.push(c); 
        } else { 
            if (st.empty() || 
                (c == ')' && st.top() != '(') || 
                (c == '}' && st.top() != '{') ||
                (c == ']' && st.top() != '[')) {
                return false;
            }
            st.pop(); 
        }
    }
    return st.empty();
}

void init_code(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
}

int main(){
    init_code();
    string str;
    cin >> str;
    cout << isValid(str); 
}