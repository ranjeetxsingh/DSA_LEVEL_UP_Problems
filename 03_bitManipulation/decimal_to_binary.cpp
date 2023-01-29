// decimal to binary

#include<iostream>
using namespace std;

long long int binaryConvertor(int n) {
	long long int result = 0;
	long long int power_of_10 = 1;
	while (n > 0) {
		int remainder = n % 2;
		result = result + power_of_10 * remainder;
		n = n / 2;
		power_of_10 *= 10;
	}

	return result;
}

int main() {
	int n;
	cin >> n;

	cout << "binary equivalent of " << n << " is: " << binaryConvertor(n) << endl;

	return 0;
}