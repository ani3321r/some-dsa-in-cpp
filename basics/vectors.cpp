#include<bits/stdc++.h>
using namespace std;

void vectorindepth(){
	vector<int> v;

	v.push_back(5);
	v.emplace_back(7);
	v.emplace_back(9);
	v.emplace_back(5);
	v.emplace_back(8);//this is faster than pushback

	vector <pair<int, int>>vec;

	vec.push_back({5,6});
	vec.emplace_back(2,3);

	vector<int> v1(5);//this will declare a container of 5 instances with garbage value

	vector<int> v2(5,20);//this will declare a container of 5 instances of 20

	vector<int> v3(v2);//this is how we copy a vector

	cout << v[1] << " ";// we can also access a vector with index value

	vector<int>::iterator ab = v.begin();//it points to the memory
	cout << *ab << " ";
	++ab;

	vector<int>::iterator ac = v.end();//it points to the memory address just after the last index

	//vector<int>::iterator ad = v.rend();//it points to the memory address just in front of the first address

	//vector<int>::iterator ae = v.rbegin();//it points to the last element and iterates in a reverse manner

	cout << endl;

	cout << v.back() << endl;//print the last element

	for(vector<int>::iterator ba = v.begin(); ba != v.end(); ba++){
		cout << *(ba) << " ";
	}//looping through a vector

	cout << endl;	

	for(auto ca = v.begin(); ca != v.end(); ca++){
		cout << *(ca) << " ";
	}//a more simpler way	

	cout << endl;

	for(auto da: v){
		cout << da << " ";
	}//simplest way of looping through a vector using for each loop

	v.erase(v.begin() + 1);//erasing an element of the vector

	v.erase(v.begin(), v.begin() + 2);// erasing more than one element

	//insertion

	vector<int>vs(3,200);//3 instances of 200
	vs.insert(vs.begin(), 600);//this will insert 600 at the front of the vector
	vs.insert(vs.begin() + 1, 2 , 400);//this will insert 2 instances of 400 at the 1st index

	vector<int> copy(2,60);
	vs.insert(vs.begin(), copy.begin(), copy.end());//this will insert the whole copy vector at the front of vs vector

	vs.pop_back();//pop the last element of the vector

	vs.swap(copy);//swap the vectors

	vs.clear();// erases all the elements of the vector

	cout << endl;

 	cout << vs.empty() << endl;// checks if the vector is empty or not. Returns a true or false value		
}

int main(){
	vectorindepth();
	return 0;
}