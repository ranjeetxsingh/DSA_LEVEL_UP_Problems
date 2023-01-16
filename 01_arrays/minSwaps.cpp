// question - minimum
/*
	Given an array of size N, find the minimum number of swaps needed to make the array sorted

	input: [5,4,3,2,1]

	output: 2

	input : [10, 11, 5, 4, 3, 2, 1]

	output: 4
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int countMinSwap(vector<int> arr) {

	//know the actual positions of the elements (sorting)
	// store the current indices
	int ans = 0;
	int n = arr.size();
	pair<int, int> ap[n];
	for (int i = 0; i < n; i++) {
		ap[i].first = arr[i];
		ap[i].second = i;
	}

	//sorting
	sort(ap, ap + n);

	//build the main logic
	vector<bool> visited(n, false);

	for (int i = 0; i < n; i++) {

		//if element is visited or element is in right position
		int old_position = ap[i].second;

		if (visited[i] == true or old_position == i)
			continue;


		//visiting the element (index) for the first time
		int node = i;
		int cycle = 0;

		while (!visited[node]) {
			visited[node] = true;
			int next_node = ap[node].second;
			node = next_node;
			cycle += 1;
		}

		ans += (cycle - 1);

	}

	return ans;
}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> arr{10, 11, 5, 4, 3, 2, 1};
	cout << countMinSwap(arr) << endl;

	return 0;
}