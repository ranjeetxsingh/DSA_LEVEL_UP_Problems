// question - tripletSum
/*
	Given an array containing N integers, and a number S denoting a target sum
	Find all distinct integers that can add upto form target sum.The numbers in
	each triplet should be ordered in ascending order, and the triplets should be
	ordered too. Return an empty array if no such triplet such exists.

	input = [1, 2,3,4,5,6,7,8,9,15]
	target = 18

	output
	[[1,2,15],
	 [3,7,8],
	 [4,6,8],
	 [5,6,7]]

	 solution:

	 1:	Brute force solution where we put three loops and its time complexity will be O(N^3)

	 2: We can also approach this problem as a pair sum problem where in we have first number
	 as 1, and now we need to find whether (18-1=17) exist in the rest of the array or not and
	 that we can look up by considering pair sum problem in rest of the array.
	 its time complexity will be O(N*N)

	 3: firstly we will sort our array, then we will iterate over the entire array and pick an element
	 a[i], and solve pair sum problem for the rest of the array using two pointer approach.
	 In this two pointer approach of pair sum problem we firstly need a sorted array and now consider start and end
	 points eg. a[s] and a[e] and calculate their sum, if the sum if more than target sum then we decrease the end counter
	 and if the sum is less than the target sum then we increase the start counter.
	 overall complexity will be: O(N log N) for sorting + O(N*N) for finding triplets, O(N*LogN + N*N) = O(N*N)

	 we have not used two pointer approach for solving actual pair sum problem because there sorting will take O(N*Log N) time
	 and finding the pair will take O(N) time, so there sorting actually becomes bottleneck for our problem and increases the
	 time complexity for our code.
*/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

vector<vector<int>> triplets(vector<int> arr, int sum) {
	// logic
	sort(arr.begin(), arr.end());
	int n = arr.size();
	int a = 0, b = 0;

	vector<vector<int>> ans;

	//pick every a[i] and pair sum the remaining
	for (int i = 0; i <= n - 3; i++) {

		int currentSum = 0;
		int s = i + 1;
		int e = n - 1;

		//two pointer approach
		while (s < e) {
			currentSum = arr[i] + arr[s] + arr[e];
			if (currentSum == sum) {
				ans.push_back({arr[i], arr[s], arr[e]});
				s++;
				e--;
			}
			else if (currentSum > sum)
				e--;
			else if (currentSum < sum)
				s++;
		}

	}

	return ans;

}


int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
	int s = 18;

	auto result = triplets(arr, s);

	for (auto v : result) {
		for (auto no : v) {
			cout << no << ", ";
		}
		cout << endl;
	}

	return 0;
}