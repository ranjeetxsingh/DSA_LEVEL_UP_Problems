#include<iostream>
using namespace std;

int getIthBit(int n, int i) {
	int mask = (1 << i);
	if ((n & mask) > 0)
		return 1;
	else
		return 0;
}

void setIthBit(int &n, int i) {
	int mask = (1 << i);
	n = (n | mask);
}

void clearIthBit(int &n, int i) {
	int mask = (1 << i);
	mask = ~(mask);

	n = (n & mask);
}

void updateIthBit(int &n, int i, int v) {

	clearIthBit(n, i);
	int mask = (v << i);
	n = (n | mask);
}


void clearLastIBits(int &n, int i) {
	int mask = -1 << i;
	n = n & mask;

}

int main() {
	int n, i;

	/*
	cout << "enter number and i-th index to get bit for it: ";
	cin >> n >> i;

	cout << "i-th bit is: " << getIthBit(n, i) << endl;

	cout << "Enter number and position to set bit: ";
	cin >> n >> i;
	cout << "Entered value of N: " << n << endl;
	setIthBit(n, i);
	cout << "New value of N: " << n << endl;

	cout << "Enter number and position to clear bit: ";
	cin >> n >> i;
	cout << "Entered value of N: " << n << endl;
	clearIthBit(n, i);
	cout << "New value of N: " << n << endl;

	int v;
	cout << "Enter number and position and value to update bit: ";
	cin >> n >> i >> v;
	cout << "Entered value of N: " << n << endl;
	updateIthBit(n, i, v);
	cout << "New value of N: " << n << endl;
	*/

	cout << "Enter number and value of i to clear last i bit: ";
	cin >> n >> i ;
	cout << "Entered value of N: " << n << endl;
	clearLastIBits(n, i);
	cout << "New value of N: " << n << endl;

	return 0;
}