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
		friend class boost::serialization::access;
		template<class Archive>
			void serialize(Archive & ar, const unsigned int version)
			{
				ar & myMap;
				ar & wordPos;
			}
		string word;	//-Word input
		string def;	//-Word def input
		int index;	//-Sequence
	public:
		DataStructures();
		map<string, string> myMap;
		map<string, int> wordPos;
		void add(const string word, const string def, const string in); 
		void rm(const int index);
		void display();
		void update(const string word, const string def, const string in);
		string recent() const;
		string search(const string word) const;
};
