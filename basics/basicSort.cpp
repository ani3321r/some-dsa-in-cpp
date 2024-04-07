#include<bits/stdc++.h>
using namespace std;

bool comp(pair<int,int>p1, pair<int,int>p2){
	if(p1.second < p2.second) return true;
	if(p1.second > p2.second) return false;

	if(p1.first > p2.first) return true;
	return false;
}//this is required to sort the conditions given below

void someBasicSort(){
	v[] = {1, 5, 6, 9, 2 ,3}

	sort(a, a+n);
	sort(v.begin(), v.end());

	sort(a+2, a+4);// when we want a certain portion of the array to be sorted

	sort(a, a+n, greater<int>);//it automatically sorts the array in descending order

	pair<int, int> a1[] = {{1,5},{3,2},{4,2}};

	//sorting in ascending according to the second
	//element and if the elements are same then sort
	//according to the first element but in descending order

	sort(a1,a1+2,comp);

	int num = 6;
	int cnt = __builtin_popcount();//it gives the number of 1's of the number converted to binary

	long long num = 612125151;
	int cnt = __builtin_popcountll();//for long long datatype

	string s = "156";// it is always reccomended to give a sorted string to get all the permutations

	sort(s.begin(), s.end());

	do{
		cout << s << endl;
	} while(next_permutation(s.begin(), s.end()));//it gives the possible permutations of the string

	int maximum = *max_element(a,a+n);//to get the max element, also u can use min same as max
}

int main(){
	someBasicSort();
	return 0;
}