#include<iostream>
using namespace std;

//fast exponentioation

int fastExponentiation(int a, int b) {
	//we will be doing a^b
	int result = 1;
	int power_a = a;
	while (b > 0) {
		if (b & 1 == 1) {
			result = result * power_a;
		}
		b = b >> 1;
		power_a *= power_a;
	}

	return result;

}


int main() {
	int a, b;

	cin >> a >> b;

	cout << fastExponentiation(a, b) << endl;

	return 0;
}