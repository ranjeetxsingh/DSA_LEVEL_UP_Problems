#include<iostream>
using namespace std;

//counting set bits

//faster method
int countBitsHack(int n) {
	int ans = 0;
	while (n > 0) {
		//removes the last set bit from the current number
		n = n & (n - 1);
		ans++;
	}

	return ans;
}

int main() {
	cout << "Enter a number: ";
	int n;
	cin >> n;
	int cnt = 0;

	while (n != 0) {
		cnt += (n & 1);
		n = n >> 1;
	}

	cout << "Count of set bits is: " << cnt;

	return 0;
}