#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "datastructures.h"
using namespace std;

DataStructures::DataStructures(){
	index = 1;
}

void DataStructures::add(const string word, const string def, const string in){ 		//-Adding new word and its definition into the map 
	if (myMap.count(word)){						//-Checking if that word is already existed
		cout << word << " is already defined. Update? (Y/N)";
		string input;
		cin >> input;
		if (input.compare("Y") == 0){
			return DataStructures::update(word, def);	//-If yes going to the update function
		}else{
			return;
		}	
	}else {
		myMap[word] = def;		//-If no adding the new word
		wordPos[word] = index;		//-Keeping track with the sequence of the map
		index+=1;
	}

}


void DataStructures::update(const string word, const string def, const string in){
	if (myMap.count(word)){			// -Update the existed word
		myMap[word] = def;
	}else{					//-If that word is not exist -> creating a new one by using add function
		return DataStructures::add(word, def);
	}

}

void DataStructures::display() {	//-Print out all the element of the map, word
	map<string, string>::const_iterator it;
	for (it = myMap.begin(); it != myMap.end() ; it++){
		cout << wordPos[it->first] << ": " << it->first << ": " << it->second << endl;
	}
}

void DataStructures::rm(const int index){	//-Removing one of the word of the map
	map<string, string>::const_iterator it;	//-Iterate through the map in order to get the string

	for (it = myMap.begin(); it != myMap.end(); it++){
		if (wordPos[it->first] == index){
			myMap.erase(it->first);
			wordPos.erase(it->first);
		}

	}
}

string DataStructures::recent() const{		//-Function return the lastest word that put into the map
	map<string, string>::const_iterator it = myMap.end();
	string result = "";
	result.append(it->first);
	result.append(": ");
	result.append(it->second);
	return result;
}

string DataStructures::search(const string word) const{		//-Function searching through the map find the definition, return the def of that word
	map<string, string>::const_iterator it;
	string result = "";	//-Empty string to add to make a sentence
	for (it = myMap.begin(); it != myMap.end(); it++){
		if (it->first.compare(word) == 0){
			result.append(it->first);
			result.append(": ");
			result.append(it->second);
			return result;
		}
	}
	return "Can't find any word";	//-return this statement if didn't not find that word
}
