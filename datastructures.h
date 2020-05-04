#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class DataStructures {
	private:
		string word;
		string def;
	public:
		DataStructures();
		map<string, string> myMap;
		vector<map<string, string> > myvec;
		void add(const string word, const string def);
		void rm(const int index);
		void display();
		void update(const string word, const string def);
		string recent() const;
};
