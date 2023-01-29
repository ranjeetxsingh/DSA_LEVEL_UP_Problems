#include<iostream>
using namespace std;

int main() {
	cout << "Enter a number: " ;
	int n;
	cin >> n;

	if ((n & (n - 1)) == 0)
		cout << "power of 2" << endl;
	else
		cout << "not power of 2" << endl;

	return 0;
}