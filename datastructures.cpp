#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "datastructures.h"
using namespace std;

DataStructures::DataStructures(){
}

void DataStructures::add(const string word, const string def){
	if (myMap.count(word)){
		cout << word << " is already defined. Update? (Y/N)";
		string input;
		cin >> input;
		if (input.compare("Y") == 0){
			return DataStructures::update(word, def);
		else {
			break;
		     }
		}	
	}else {
		myMap[word] = def;
	}
	myvec.push_back(myMap);
}


void DataStructures::update(const string word, const string def){
	myMap[word] = def;
	for (int i = 0; i < myvec.size(); i++){
		if (myvec[i].compare(word) == 0){
			myvec[i][word] = def;
		}
	}
}

void DataStructures::display() {
	int num = 0;
	map<string, string>::iterator it;
	for (it = myMap.begin(); it != myMap.end() ; it++){
		cout << num << ". " << it->first << ": " << it->second << endl;
		num++;
	}
}

void DataStructures::rm(const int index){
	vector<string> another;
	map<string, string>::iterator it;
	myvec.erase(myvec.at(index-1);

	for (it = myMap.begin(); it != myMap.end(); it++){
		another.push_back(it->first);
	}	
	mymap.erase(myvec.at(index-1));
}

string DataStructures::recent() const{
	return "a";
}
