#include<bits/stdc++.h>
using namespace std;

void pattern1(int n){
	for(int  i=0; i<n; i++){
		for(int  j=0; j<n; j++){
			cout << "*";
		}
		cout << endl;
	}
}
void pattern2(int n){
	for(int  i=0; i<n; i++){
		for(int  j=0; j<=i; j++){
			cout << "* ";
		}
		cout << endl;
	}
}
void pattern3(int n){
	for(int  i=1; i<=n; i++){
		for(int  j=1; j<=i; j++){
			cout << j << " ";
		}
		cout << endl;
	}
}
void pattern4(int n){
	for(int  i=1; i<=n; i++){
		for(int  j=1; j<=i; j++){
			cout << i << " ";
		}
		cout << endl;
	}
}
void pattern5(int n){
	for(int  i=1; i<=n; i++){
		for(int  j=1; j<n-i+j; j++){
			cout << "* ";
		}
		cout << endl;
	}
}
void pattern6(int n){
	for(int  i=1; i<=n; i++){
		for(int  j=1; j<n-i+j; j++){
			cout << j << " ";
		}
		cout << endl;
	}
}
void pattern7(int n){
	for(int  i=0; i<n; i++){
		for(int  j=0; j<n-i-1; j++){
			cout << " ";
		}

		for(int  j=0; j<2*i+1; j++){
			cout << "*";
		}

		for(int  j=0; j<n-i-1; j++){
			cout << " ";
		}
		cout << endl;
	}
}
void pattern8(int n){
	for(int  i=0; i<n; i++){
		for(int  j=0; j<i; j++){
			cout << " ";
		}

		for(int  j=0; j<2*n-(2*i +1); j++){
			cout << "*";
		}

		for(int  j=0; j<i; j++){
			cout << " ";
		}
		cout << endl;
	}
}
void pattern10(int n){
	for(int i=1; i<=2*n-1; i++){
		int star = i;
		if(i>n) star = 2*n -i;
		for(j=1; j<=star; j++){
			cout << "*";
		}
		cout << endl;
	}
}
void pattern11(int n){
	int start = 1;
	for(int i=0; i<n; i++){
		if(i%2 == 0) start = 1;
		else start = 0;
		for(int j=0; j<=i; j++){
			cout << start;
			start = 1 - start;
		}
		cout << endl;
	}
}

int main(){
	int n;
	cin >> n;
	pattern1(n);
	pattern2(n);
	pattern3(n);
	pattern4(n);
	pattern5(n);
	pattern6(n);
	pattern7(n);
	pattern8(n);
	//pattern 9 is combined 7 & 8
	pattern10(n);

}