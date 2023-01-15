/* question - rains

	Given N non-negative integers representing an elevation map where the width of each bar is 1,
	compute how much water it can trap after raining.

	input: [0,1,0,2,1,0,1,3,2,1,2,1]
	output: 6

*/

#include<iostream>
#include<vector>
using namespace std;

int trappedWater(vector<int> heights) {
	int n = heights.size();

	// corner cases
	if (n <= 2)
		return 0;

	//Left Max and Right Max
	vector<int> left(n, 0), right(n, 0);
	left[0] = heights[0];
	right[n - 1] = heights[n - 1];

	for (int i = 1; i < n; i++) {
		left[i] = max(left[i - 1], heights[i]);
		right[n - 1 - i] = max(right[n - i], heights[n - 1 - i]);
	}

	int water = 0;

	for (int i = 0; i < n; i++) {
		water += (min(left[i], right[i]) - heights[i]);
	}

	return water;

}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> water = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

	cout << trappedWater(water) << endl;

	return 0;
}