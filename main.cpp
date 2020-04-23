#include <iostream>
#include <string>
#include "stats.h"
#define ar array
using namespace std;

string a[2];

string getCommand() {
	for (int i = 0; i < 2; i++){
		cin >> a[i];
	}
	return a[1];
}

int main() {
	while (true){
		string user_input = getCommand();
		if (user_input.compare("stats") != 0){
			string textInput;
			cout << user_input << ": ";
			cin >> textInput;
			Stats a(user_input, textInput);
		
		}else{
			a.display();
		}
	}
	return 0;
}
