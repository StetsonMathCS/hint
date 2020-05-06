#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ctime>
#include <time.h>
#include "datastructures.h"
#include <fstream>
////serialization
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

//for extended classes
#include <boost/serialization/base_object.hpp>
//each of the stl containers have a file such as list.hpp, vector.hpp, set.hpp
#include <boost/serialization/map.hpp>
#include <boost/serialization/string.hpp>

#define ar array
using namespace std;

// -Display the output
void display(map<string, map<string, string> > *myMap, map<string, map<string, int> > *count, vector<string> *myvec){

	// -Iterators point to map and vector
	map<string, map<string, string> >::const_iterator it;
	map<string, string>::const_iterator another;
	vector<string>::const_iterator iter;

	cout << "History of commands: " << endl;
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

////Serialization

//saves serialized archive to a file
void save_hints(const DataStructures& hints)
{
        string homedir = string(getenv("HOME"))+"\\hints.txt";
        //saves in user
        ofstream ofh(homedir.c_str());
        //saves on system
                //ofstream ofs(system);
        boost::archive::text_oarchive oah(ofh);
                //boost::archive::text_oarchive oas(ofs);
        oah << hints;
        //oas << hints;
}


//load serialized archive to a file
void load_hints(DataStructures& hints)
{
        string homedir = string(getenv("HOME"))+"\\hints.txt";
        ifstream ifs(homedir.c_str());
        //if xml, boost::archive::xml_iarchive ia(ifs);
        boost::archive::text_iarchive ia(ifs);
        //serialize(oa, 1)
        ia >> hints;
}


// -Main file fixed by Cas
int main(int argc, char** argv) {
	DataStructures data();
	map<string, map<string, string> > myMap; // -Create map to store specific command value (eg. hint search for csci221 will be store into the map and time did)
	map<string, map<string, int> > count;    // -Create map to store numbers of that commands use
	vector<string> myvec;			 // -Vector to store the history of commands use
	if (argc > 1){
		string user_input = (string) argv[1];
		while (true){
			time_t thetime = time(0); // -Created current date and time while using the command
			string mytime = asctime(localtime(&thetime));

			if ((user_input.compare("stats") == 0)){
				display(&myMap, &count, &myvec); 
				myvec.push_back(user_input);

			}else if(user_input.compare("recent") == 0){
				cout << "Recent command: " << endl;
				cout << "'" << myvec.back() << "'" << endl; 	// -Prints out the last element of the vector 

			}else{ 
				// From Cas - Sorry, wasn't really sure what this section did? It seems to record inputs, but those inputs should be
				// recorded in their specific sections, right? 
				string textInput;
				string another; // I can't remember if this was a string or not but this variable was deleted at some point so it can't compile without it
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
			if(user_input.compare("ask") == 0) { // needs to either be a new if, or the previous "else" needs to have a conditional

			}
			else if(user_input.compare("help") == 0) {

			}
			else if(user_input.compare("report") == 0) {

			}
			else if(user_input.compare("random") == 0) {

			}
			else if(user_input.substr(0, 7) == "search "){
				string to_search = user_input.substr(7); // records what is being searched
				cout << "searching for " << to_search << "..." << endl;
				// perform search funciton. Return information or return "not found" if the to_search comes up with nothing
			}
			else if(user_input.substr(0, 3) == "rm ") {
				string to_rm = user_input.substr(3); //records what is to be removed
				cout << "removing " << to_rm << "..." << endl;
				//perform function to remove. Return cout "removed" if found, or "not found" if to_rm finds nothing
			}
			else if(user_input.substr(0, 5) == "edit ") {
				string to_edit = user_input.substr(5); //records what is to be edited
				cout << "editing " << to_edit << "..." << endl;
				//open editing function or return "not found" if not found
			}
			else if(user_input.substr(0, 8) == "comment ") {
				string to_comment = user_input.substr(8); //records what is to be commented on
			}
			else if(user_input.substr(0, 8) == "suggest ") {
				string to_suggest = user_input.substr(8); // record what is to be suggested on
				// perform suggest function
			}
			else if(user_input.substr(0, 4) == "tag ") {
				string to_tag = user_input.substr(4); // record what is to be tagged
				// perform tag function
			}
			else if(user_input.substr(0, 7) == "answer ") {
				string to_tag = user_input.substr(7); // record what is to be answered
				// perform answeer function
			}
			// should a quit function also be added to end the program?
			else if(user_input.substr(0, 3) == "add"){
				string hint_input = "";
				string input = "";
				data.add("hint", hint_input, input);
			}else if(user_input.substr(0, 7) == "display") {
				data.display();	
			}else if(user_input.substr(0, 7) == "remove ") {
				int index;
				cin >> index;
				data.rm(index);
			}else if(user_input.substr(0, 5) == "update") {
				string hint_input = "";
				string input = "";
				data.update("hint", hint_input, input);
			}else if(user_input.substr(0, 5) == "recent") {
				data.recent();
			}
			else {
				cout << "Invalid input " << user_input << endl;
			}
		}
	}else{
		cout << "Not enough information" << endl;
	}
		return 0;	// -main needs to return 0 hehe ^^
	}
