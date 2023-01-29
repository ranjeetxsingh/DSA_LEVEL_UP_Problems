/*
question - sorted subsequences

you are given a string, you need to print all the subsequence of a string
sorted by length and lexicographic sorted order if length is same.

sample input:-
	abcd

sample output:-
,a,b,c,d,ab,ac,ad,bc,bd,cd,abc,abd,acd,bcd,abcd,
*/

#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

//sorted subsequence


void subsequence(string s, string o, vector<string> &v) {

	// base case
	if (s.size() == 0) {
		v.push_back(o);
		return;
	}

	//rec case

	string reduced_input = s.substr(1);
	char ch = s[0];

	subsequence(reduced_input, o + ch, v);
	subsequence(reduced_input, o, v);


}

bool compare(string s1, string s2) {

	if (s1.length() == s2.length()) {
		return s1 < s2;
	}
	else {
		return s1.length() < s2.length();
	}
}

int main() {

	string s;
	cin >> s;
	vector<string> v;
	string output = "";
	subsequence(s, output, v);

	sort(v.begin(), v.end(), compare);
	for (auto x : v) {
		cout << x << ", ";
	}


	return 0;
}