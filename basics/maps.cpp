#include<bits/stdc++.h>
using namespace std;

void someMap(){
	//map store unique keys in sorted order

	map<int, int> mp;
	map<int, pair<int, int>> mp1;//key is one int value is two ints
	map<pair<int, int>, int> mp2;//key is two ints and value is one int

	mp[1] = 2;// stores as {1,2}
	mp[5] = 4;
	mp[6] = 3;
	//mp.emplace({3,6});
	//mp.insert({4,8});

	mp2[{5,6}] = 15;//stored as {{5,6},15}

	for(auto it: mp){
		cout << it.first << " " << it.second <<endl;
	}

	cout << mp[1];
	cout << mp[6];//it gives null because it doesn't exist

	auto it2 = mp.find(5);
	cout << *(it2).second << endl;//second element of the element, i.e, 4.

	 auto it3 = mp.lower_bound(5);
	 auto it4 = mp.upper_bound(6);
}

void someMultiMap(){
	//just can store duplicate keys
}

void someUnorderedMap(){
	//stores unique keys but stores everything in a unordered fashion
}

int main(){
	someMap();
	return 0;
}