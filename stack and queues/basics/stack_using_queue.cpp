#include<bits/stdc++.h>
using namespace std;

class MyStack {
    private:
    queue<int> q;
    public:
    void Push(int x) {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s-1; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    int Pop() {
        int n = q.front();
        q.pop();
        return n;
    }
    int Top() {
        return q.front();
    }
    int Size() {
        return q.size();
    }
};

