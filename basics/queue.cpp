#include<bits/stdc++.h>
using namespace std;

void someQueue(){
	queue<int> q;
	q.push(1);
	q.push(9);
	q.emplace(6);

	q.back() += 4;// here the last value is incrimented by 4

	cout << q.back() << endl;

	cout << q.front() << endl;

	q.pop();

	cout << q.front() << endl;
}

void somePQueue(){
	//this is max heap
	priority_queue<int>pq;
	pq.push(3);
	pq.push(5);//log n
	pq.push(6);
	pq.emplace(7);

	cout << endl;

	cout << pq.top() << endl;//this shows the largest value
	pq.pop();// this pops the largest number
	cout << pq.top() << endl;// O(1)

	//this is min heap
	priority_queue<int, vector<int>, greater<int>>eq;//this is how we store the queue in the reverse order
	eq.push(10);
	eq.push(9);
	eq.push(8);
	eq.emplace(11);

	cout << eq.top() << endl;
}


int main(){
	someQueue();
	somePQueue();
	return 0;
}