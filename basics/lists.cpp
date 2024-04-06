#include<bits/stdc++.h>
using namespace std;

void somelist(){
	list<int> ls;

	ls.push_back(5);
	ls.emplace_back(9);

	ls.push_front(8);// insert is much most costly than push function
	ls.emplace_front(6);

	//all the other functions are same as vector
	//begin,end,rbegin,rend,clear,insert,size,swap	
}

int main(){
	somelist();
	return 0;
}