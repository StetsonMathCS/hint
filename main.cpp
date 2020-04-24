#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <time.h>

#define ar array
using namespace std;

string a[2];

string getCommand() {
	for (int i = 0; i < 2; i++){
		cin >> a[i];
	}
	return a[1];
}

void display(map<string, map<string, string> > *myMap, map<string, map<string, int> > *count, vector<string> *myvec){
	map<string, map<string, string> >::const_iterator it;
	map<string, string>::const_iterator another;
	


	for (it = myMap->begin(); it != myMap->end(); it++){
		for(another = it->second.begin(); another != it->second.end(); another++){
			cout << "Users " << it->first << " " << another->first << " " << count->at(it->first).at(another->first)  << " time(s)" << endl;
		}
	}
}

int main() {
	map<string, map<string, string> > myMap;
	map<string, map<string, int> > count;
	vector<string> myvec;

	while (true){
		string another = "";
		string user_input = getCommand();
		time_t thetime = time(0);
		string mytime = asctime(localtime(&thetime));

		if ((user_input.compare("stats") == 0)){
			display(&myMap, &count, &myvec);	
		}else if(user_input.compare("recent") == 0){
			cout << "Recent command: " << endl;
			cout << "'" << myvec.back() << "'" << endl;	
		}else{
			string textInput;
			cout << user_input << ": ";
			cin >> textInput;
			myMap[user_input][textInput] = mytime;
			another.append(user_input);
			another.append(": ");
			another.append(textInput);
			another.append(" at ");
			another.append(mytime);
			myvec.push_back(another);	

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
	return 0;
}
