/*
question - string tokenization

tokenizing a string denotes splitting a string with respect to some delimitter(s)

input : "today is sunny day"

output: "today","is","sunny","day"

1. using stringstream class
2. using strtok function

*/

#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

int main() {

	string input;
	getline(cin, input);

	//create a string stream object
	stringstream ss(input);

	// >> and << operators
	string token;
	vector<string> tokens;
	while (getline(ss, token, ' ')) {
		tokens.push_back(token);
	}

	for (auto t : tokens)
		cout << t << ", ";

	return 0;

}