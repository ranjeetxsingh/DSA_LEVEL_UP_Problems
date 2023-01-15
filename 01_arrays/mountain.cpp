// question - mountain
/*
	write a function that takes input an array of distinct integers, and returns length of highest mountain

	* a mountain is defined as adjacent integers that are strictly increasing until they reach a peak
	after which it becomes it strictly decreasing.

	Atleast three numbers are required to form a mountain.

	input = [5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1,2, 3, -2, 4]
	output: 9

*/

#include<iostream>
#include<vector>
using namespace std;

int highest_mountain(vector<int> a) {
	int n = a.size();

	/*
	// my solution

	int highestPeakLength = 0;
	int maxPeakIndex = -1;

	for (int i = 1; i < n-1; i++) {
		if (arr[i - 1] < arr[i] and arr[i + 1] < arr[i]) {
			int j = i;
			int c = 1;
			while (arr[j - 1] < arr[j]) {
				c++;
				j--;
			}
			j = i;
			while (arr[j + 1] < arr[j]) {
				c++;
				j++;
			}
			highestPeakLength = max(highestPeakLength, c);
		}
	}

	return highestPeakLength;
	*/

	// proper solution
	int largest = 0;
	for (int i = 1; i <= n - 2;) {

		// check a[i] is a peak or not
		if (a[i] > a[i - 1] and a[i] > a[i + 1]) {
			int cnt = 1;
			int j = i;
			// cnt backwards (left)
			while (j >= 1 and a[j] > a[j - 1]) {
				cnt++;
				j--;
			}
			// cnt forwards (right)
			while (i <= n - 2 and a[i] > a[i + 1]) {
				cnt++;
				i++;
			}

			largest = max(largest, cnt);
		} else {
			i++;
		}
	}

	return largest;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> arr{5, 6, 1, 2, 3, 4, 5, 4, 3, 2, 0, 1, 2, 3, -2, 4};

	int peakLength = highest_mountain(arr);
	cout << peakLength << endl;

	return 0;
}