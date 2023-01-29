#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int main() {

	char input[1000];
	cin.getline(input, 1000);

	//strtok()

	// this function internally maintains the state of string that we passed in the last function call
	//by making a static variable we are able to maintain the state
	char *token = strtok(input, " ");
	cout << token << endl;

	while (token != NULL) {

		cout << token << endl;
		token = strtok(NULL, " ");

	}

	return 0;
}