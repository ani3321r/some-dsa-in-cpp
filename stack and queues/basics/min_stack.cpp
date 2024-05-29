#include<bits/stdc++.h>
using namespace std;

class MinStack{
    stack<long long> st;
    long long mini;
    public:
        MinStack(){
            while(st.empty() == false) st.pop();
            mini = INT_MAX;
        }
        void Push(int value){
            long long val = value;
            if(st.empty()){
                mini = val;
                st.push(val);
            }
            else{
                if(val < mini){
                    st.push(2*val*1LL-mini);
                    mini = val;
                }
                else{
                    st.push(val);
                }
            }
        }
        void Pop(){
            if(st.empty()) return;
            long long el = st.top();
            st.pop();
            if(el<mini){
                mini = 2*mini-el;
            }
        }
        int Top(){
            if(st.empty()) return -1;
            long long el = st.top();
            if(el<mini) return mini;
            return el;
        }
        int getMin(){
            return mini;
        }
};

int main() {
    MinStack minStack;
    minStack.Push(-2);
    minStack.Push(0);
    minStack.Push(-3);
    cout << "Minimum element in the stack: " << minStack.getMin() << endl;
    minStack.Pop();
    cout << "Top element in the stack: " << minStack.Top() << endl;
    cout << "Minimum element in the stack after popping: " << minStack.getMin() << endl;
    return 0;
}