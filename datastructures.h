#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class DataStructures {
	private:
		string word;	//-Word input
		string def;	//-Word def input
		int index = 1;	//-Sequence
	public:
		DataStructures();
		map<string, string> myMap;
		map<string, int> wordPos;
		void add(const string word, const string def);
		void rm(const int index);
		void display();
		void update(const string word, const string def);
		string recent() const;
		string search(const string word) const;
};
