// question - subarray sort
/*
	Given an array of size atleast two, find the smallest subarray that needs
	to be sorted in a place so that entire input array becomes sorted.
	If the input is already sorted, the function should return [-1,-1],
	otherwise return the start and end index of smallest subarray.

	input: [1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11]

	output: [5, 7]

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

bool outOfOrder(vector<int> arr, int i) {
	int x = arr[i];
	if (i == 0)
		return x > arr[1];
	if (i == arr.size() - 1)
		return x < arr[i - 1];
	return x > arr[i + 1] or x < arr[i - 1];
}

pair<int, int> subArraySort(vector<int> arr) {
	int n = arr.size();
	int smallest = INT_MAX;
	int largest = INT_MIN;

	for (int i = 0; i < n; i++) {
		int x = arr[i];
		if (outOfOrder(arr, i)) {
			smallest = min(smallest, x);
			largest = max(largest, x);
		}
	}

	if (smallest == INT_MAX) {
		return { -1, -1};
	}

	int left = 0;
	while (smallest >= arr[left])
		left++;

	int right = n - 1;
	while (largest <= arr[right])
		right--;

	return {left, right};
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};

	auto p = subArraySort(arr);

	cout << p.first << " and " << p.second << endl;

	return 0;
}