#include<bits/stdc++.h>
using namespace std;

void someDeque(){
	deque<int>dq;
	dq.push_back(5);
	dq.emplace_back(3);
	dq.push_front(8);
	dq.emplace_front(6);

	dq.pop_back();
	dq.pop_front();

	for(auto a: dq){
		cout << a << " ";
	}

	//all the other functions are same as vector
	//begin,end,rbegin,rend,clear,insert,size,swap	
}

void someStack(){
	stack<int> st;
	st.push(5);
	st.push(8);
	st.push(9);
	st.push(7);
	st.emplace(6);

	cout << st.top() << endl;

	st.pop();

	cout << st.top() << endl;// stack elements cannot be accessed with indexes
	cout << st.size() << endl;
	cout << st.empty() << endl;

	stack<int>st1, st2;
	st1.swap(st2);

}

int main(){
	someDeque();
	someStack();
	return 0;
}