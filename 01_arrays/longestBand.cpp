// question - longest band
/*
	given an array containing N integers, find the length of longest band

	a band is defined as a subsequence which can be re-ordered in such a manner
	all elements appear consecutive(i.e. absolute difference of 1 between the neighbouring elements)

	a longest band is the band(subsequence) which contains maximum integers.

	input array:
					[1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6]
	output: 8

	explanation:
	largest subset containing consecutive numbers is {0,1,2,3,4,5,6,7}


*/

#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int largestBand(vector<int> arr) {
	int n = arr.size();
	unordered_set<int> s;

	for (auto x : arr) {
		s.insert(x);
	}

	int longestBand = 1;
	for (auto element : arr) {
		int parent = element - 1;
		if (s.find(parent) == s.end()) {
			int cnt = 1;
			int next_no = element + 1;
			while (s.find(next_no) != s.end()) {
				cnt++;
				next_no++;
			}
			longestBand = max(longestBand, cnt);
		}
	}

	return longestBand;
}

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> arr{1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
	cout << largestBand(arr) << endl;

	return 0;
}