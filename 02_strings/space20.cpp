/*
Question Name : space 20

Given a string, write a function to replace all spaces in string with '%20'.
It is given that the string has sufficient  space at the end to hold the additional characters

sample input: "Hello world, how are you?"

output: Hello%20world,%20how%20are%20you?

*/

#include<iostream>
#include<cstring>
using namespace std;


void replace_space(char *str) {

	//count spaces

	int space = 0;
	int characters = 0;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == ' ')	space += 1;
		characters++;
	}

	int idx = strlen(str) + 2 * space;
	str[idx] = '\0';

	// cout << "spaces = " << space << endl;
	// cout << "characters = " << characters << endl;
	// cout << "length is = " << strlen(str) << endl;

	for (int i = strlen(str) - 1; i >= 0; i--) {
		char ch = str[i];
		if (ch == ' ') {
			str[idx - 1] = '0';
			str[idx - 2] = '2';
			str[idx - 3] = '%';
			idx = idx - 3;
		}
		else {
			str[idx - 1] = ch;
			idx = idx - 1;
		}
	}
}


int main() {
	char input[1000];
	cin.getline(input, 1000);
	replace_space(input);

	cout << input << endl;

	return 0;
}