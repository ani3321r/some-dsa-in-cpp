#include<bits/stdc++.h>
using namespace std;
void pairscode() {
	pair<int, int>p = {5,6};
	cout << p.first << " " << p.second << endl;

	pair<int , pair<int, int>>e = {4, {5, 6}};
	cout << e.first << " " << e.second.second << " " << e.second.first << endl;

	pair<int, int> arr[] = {{8,9}, {6,8}, {2,5}};
	cout << arr[2].second; 

}

int main () {
	pairscode();
	return 0;
}