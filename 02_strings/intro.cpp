#include<iostream>
#include<string>
using namespace std;

int main() {
	/*
	string s;

	getline(cin, s, '.');

	for (auto ch : s)
		cout << ch << ",";

	return 0;
	*/

	// searching in string

	string paragraph = "we are learning about STL strings. STL string class is quite powerful";

	string word;
	getline(cin, word);

	//find function
	size_t index = paragraph.find(word);

	if (index == -1)
		cout << "Not Present" << endl;
	else {
		cout << "first occ = " << index << endl;
	}

	index = paragraph.find(word, index + 1);

	if (index == -1)
		cout << "No second occ" << endl;
	else
		cout << "second occ" << index << endl;

}