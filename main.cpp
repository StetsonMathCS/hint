#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <time.h>

#define ar array
using namespace std;

string a[2];

// -Getting user hint command
string getCommand() {
	for (int i = 0; i < 2; i++){
		cin >> a[i];
	}
	return a[1];
}
 // -Display the output
void display(map<string, map<string, string> > *myMap, map<string, map<string, int> > *count, vector<string> *myvec){

	// -Iterators point to map and vector
	map<string, map<string, string> >::const_iterator it;
	map<string, string>::const_iterator another;
	vector<string>::const_iterator iter;
	
	cout << "History of commanda: " << endl;
	cout << endl;
	// -Loop prints all elements inside the vector
	for(iter = myvec->begin(); iter != myvec->end(); iter++){
		cout << *iter << endl;
	}	

	// -Loop prints all elements insdie the map of couting and commands used
	for (it = myMap->begin(); it != myMap->end(); it++){
		for(another = it->second.begin(); another != it->second.end(); another++){
			cout << "Users " << it->first << " " << another->first << " " << count->at(it->first).at(another->first)  << " time(s)" << endl;
		}
	}
}

int main() {
	map<string, map<string, string> > myMap; // -Create map to store specific command value (eg. hint search for csci221 will be store into the map and time did)
	map<string, map<string, int> > count;    // -Create map to store numbers of that commands use
	vector<string> myvec;			 // -Vector to store the history of commands use

	while (true){
		string another = "", user_input = "";
		user_input = getCommand();

		time_t thetime = time(0); 	// -Created current date and time while using the command
		string mytime = asctime(localtime(&thetime));

		if ((user_input.compare("stats") == 0)){
			display(&myMap, &count, &myvec);

		}else if(user_input.compare("recent") == 0){
			cout << "Recent command: " << endl;
			cout << "'" << myvec.back() << "'" << endl; 	// -Prints out the last element of the vector 

		}else{
			string textInput;
			cout << user_input << ": ";
			cin >> textInput; 		// -Text input that user do (eg. search: csci221 -> csci221 is the textInput)
			myMap[user_input][textInput] = mytime;
			another.append(user_input); 	// -Adding all the strings together using append 
			another.append(": ");
			another.append(textInput);
			another.append(" at ");
			another.append(mytime);
			myvec.push_back(another);	// -Add that string to the back of the vector

			// -Condition counting the number of that specific command use
			if (myMap.count(user_input)){
				if (myMap[user_input].count(textInput)){
					count[user_input][textInput] += 1;
				}else {
					count[user_input][textInput] = 1;
				}
			}else{
				count[user_input][textInput] = 1;
			}
		}
	}
	return 0;	// -main needs to return 0 hehe ^^
}
