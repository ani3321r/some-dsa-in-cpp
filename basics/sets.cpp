#include<bits/stdc++.h>
using namespace std;

void someSet(){
	set<int>st;//it stores everything in a sorted order 
	st.insert(3);
	st.emplace(6);
	st.insert(5);
	st.insert(2);
	st.insert(1);

	//begin, end, rbegin, rend, size, empty, swap are same

	auto it = st.find(3);

	auto ib = st.find(8);//if an element is not present in the set, it returns set.end()

	st.erase(1);

	int cnt = st.count(2);//as a set contains only unique elements, it returns only 0 or 1

	auto id = st.find(5);
	st.erase(it);//another way of erasing 

	auto it1 = st.find(2);
	auto it2 = st.find(6);
	st.erase(it1, it2);//this erases elements between 2 and 6

	auto it = st.lower_bound(2);
	auto it = st.upper_bound(6);
}//everything happens in log n

void someMultiSet(){
	//same as set but stores duplicate elements also

	multiset<int> ms;
	ms.insert(5);
	ms.insert(5);
	ms.insert(5);

	ms.erase(5);//this erases all instances of 5

	ms.erase(ms.find(1));//erases the 1st instance of 5

	ms.erase(ms.find(1), ms.find(1)+2);//erases 1st 2 instances of 5
}
void someUnSet(){
	unordered_set<int> Ust;
	//everything is same except, the elements are stored in unordered fashion
	//lower_bound and upper_bound doesn't work
}//O(1)

int main(){
	someSet();
	return 0;
}

