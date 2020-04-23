#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

class Stats {
	private:
		int value;
		string search, tags, textSearch;
		const map<string, map<string, string> > myMap;
		const map<string, map<string, int> > total;
		const vector<string, string> myvec;
	public:
		void display();
		Stats(const string hintType, const string textType);
	       	int totalUse() const;
		string getTextSearch() const;	
};
