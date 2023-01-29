// Replace bits in N by M
/*
	You are given two 32-bit numbers, N and M, and two bit positions i and j.
	Write a method to set all bits between i and j in N equal to M.
	M (becomes a substring of N locationed at and starting at j).

	Example
	 	N = 10000000000
	 	M = 10101
	 	i = 2 and j = 6
	 	output = 1001010100
*/

#include<iostream>
using namespace std;


void clearBitsInRange(int &n, int i, int j) {
	int a = (~0) << (j + 1);
	int b = (1 << i) - 1; // setting i bits
	// example 1<<3 - 1 = 2^2 - 1 = 4 - 1 = 3 which in binaey is 011
	int mask = a | b;
	n = n & mask;
}

void replaceBits(int &n, int i, int j, int m) {
	clearBitsInRange(n, i, j);
	int mask = (m << i);
	n = n | mask;
}

int main() {

	int n = 15;
	int i = 1;
	int j = 3;
	int m = 2;

	replaceBits(n, i, j, m);

	cout << n << endl;


	return 0;
}