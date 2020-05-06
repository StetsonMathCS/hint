#include <iostream>
#include <vector>
#include <map>
#include <string>

#include <boost/serialization/vector.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/string.hpp>
using namespace std;

class DataStructures {
	private:
		string input;
		string hint_input;
		friend class boost::serialization::access;
		template<class Archive>
		void serialize(Archive & ar, const unsigned int version);
	public:
		DataStructures();
		map<string, map<string, string> > myMap;
		vector<map<string, string> > myvec;
		void add(const string hint, const string hint_input, const string input);
		void rm(int index);
		void display();
		void update(const string hint, const string hint_input, const string input);
		string recent() const;
};
