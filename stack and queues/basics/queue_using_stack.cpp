#include<bits/stdc++.h>
using namespace std;

class MyQueue {
    stack<int> s1, s2;
public:
    void Push(int x) {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s1.pop();
        }
    }

    int Pop() {
        int temp;
        while(!s1.empty()){
            temp=s1.top();
            s2.push(temp);
            s1.pop();
        }
        s2.pop();
        int last=temp;
        while(!s2.empty()){
            temp=s2.top();
            s2.pop();
            s1.push(temp);
        }
        return last;
    }
    
    int peek() {
        int temp;
        while(!s1.empty()){
            temp=s1.top();
            s2.push(temp);
            s1.pop();
        }
        int last=temp;
        while(!s2.empty()){
            temp=s2.top();
            s2.pop();
            s1.push(temp);
        }
        return last;
    }
    
    bool empty() {
        return s1.empty();
    }
};