#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

char *mystrtok(char *str, char delim) {

	static char *input = NULL;

	if (str != NULL)
		input = str;

	if (input == NULL)
		return NULL;

	char *token = new char(strlen(input) + 1);
	int i = 0;

	for (; input[i] != '\0'; i++) {
		if (input[i] != delim)
			token[i] = input[i];
		else
		{
			token[i] = '\0';
			input = input + i + 1; //static variable
			return token;
		}
	}

	// out of the loop
	token[i] = '\0';
	//reset the input as NULL
	input = NULL;
	return token;
}

int main() {

	char s[1000];
	cin.getline(s, 1000);

	//strtok()

	// this function internally maintains the state of string that we passed in the last function call
	//by making a static variable we are able to maintain the state
	char *token = mystrtok(s, ' ');

	while (token != NULL) {

		cout << token << endl;
		token = mystrtok(NULL, ' ');

	}

	return 0;
}