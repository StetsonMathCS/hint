#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "datastructures.h"
using namespace std;

DataStructures::DataStructures(){
}

void DataStructures::add(const string hint, const string hint_input, const string input){
	myMap[hint][hint_input] = input;
	myMap.insert(pair(0,1));
	myvec.push_back(myMap);
}

void DataStructures::update(const string hint, const string hint_input, const string input){
	if(myMap.count(hint)){
		if(myMap[hint].count(hint_input)){
			myMap[hint][hint_input] = input;
		}	
	}else {
		cout << "Create a new hint" << endl;
		myMap[hint][hint_input] = input;
	}
}

void DataStructures::display() {
	map<string, map<string, string> >::iterator it;
	map<string, string>::iterator another;

	for (it = myMap.begin; it != myMap.end(); it++){
		for (another = it->second.begin(); another != it->second.end(); another++){
		cout << it->first << " " << another->first << " " << another->second << endl;
	}
}

void DataStructures::rm(int index){
	int result = index - 1;
	myvec.erase(myvec.begin() + result);
	myMap.erase(myvec.at(index-1)["hint"]);
}

string DataStructures::recent() const{
	return myvec.back()["hint"]->second;
}
