/*
question - sort strings

Given a list of 'n' strings s0,s1,s2,.....,sn-1 each consisting of digits and spaces,
the number of spaces is same for each entry, the goal is to implement a variation of
sort command. None of the strings contains consecutive spaces. Also, no string
starts or ends with a space. Spaces are used to divide strings into columns, which can
be used as keys in comparisons.

the program has to support the required parameters:
key: integer denoting the column used as a key in comparisons.The left most column is
denoted by 1.
reversed: boolean variable whether to reverse the result of comparisons.

comparison-type: either lexicographic or numeric. Lexicographic means that we use
lexicographical order. where for example (122 < 13)

Numeric means that we compare strings by thier numeric values, so (13 < 122). If the
comparison type is numeric and numeric values of keys of Si and Sj are equal for i<j,
then Si is considered strictly smaller than Sj because it comes first.

*/

#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string extractStringAtKey(string str, int key) {

	//string tokenizer

	char *s = strtok((char *)str.c_str(), " ");
	while (key > 1) {
		s = strtok(NULL, " ");
		key--;
	}

	return (string) s;
}

int convertToInt(string s) {

	int ans = 0;
	int p = 1;

	for (int i = s.length() - 1; i >= 0; i--) {
		ans += ((s[i] - '0') * p);
		p *= 10;
	}

	return ans;
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2) {

	string key1, key2;
	key1 = s1.second;
	key2 = s2.second;

	return convertToInt(key1) < convertToInt(key2);

}

bool lexicoCompare(pair<string, string> s1, pair<string, string> s2) {

	string key1, key2;
	key1 = s1.second;
	key2 = s2.second;

	return key1 < key2;

}

int main() {
	int n;
	cin >> n;

	cin.get(); // will consume extra /n

	string temp;
	vector<string> v;

	for (int i = 0; i < n; i++) {
		getline(cin, temp);
		v.push_back(temp);
	}

	int key;
	string reversal, ordering;

	cin >> key >> reversal >> ordering;


	// 1. to extract keys for comparison and store them
	vector<pair<string, string>> vp;

	for (int i = 0; i < n; i++) {
		vp.push_back({v[i], extractStringAtKey(v[i], key)});
	}

	// 2. Sorting
	if (ordering == "numeric") {
		sort(vp.begin(), vp.end(), numericCompare);
	}
	else {
		sort(vp.begin(), vp.end(), lexicoCompare);
	}


	//3. reversal

	if (reversal == "true") {
		reverse(vp.begin(), vp.end());
	}


	//4. output

	for (int i = 0; i < n; i++) {
		cout << vp[i].first << endl;
	}


	return 0;

}