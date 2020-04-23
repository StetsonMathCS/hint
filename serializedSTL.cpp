#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

//for extended classes
#include <boost/serialization/base_object.hpp>
//each of the stl containers have a file such as list.hpp
#include <boost/serialization/map.hpp>
using namespace std;

class inventory
{
	//serialization is private to the inventory  class,
	//but accessible through its "friend"
	friend class boost::serialization::access;
	map<string, int> items;
	//saves or loads an archive depending on the case
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
        	//& stands in for << or >>
		ar & items;
	}
	public:
    		inventory(){}
		virtual int add_item(const string i)
		{
			if(items.find(i)==items.end())
			{
				items[i]=1;
			}
			else
			{
				items[i]++;
			}
			return items[i];
		}
		virtual int remove_item(const string i)
                {
			if(items.find(i)==items.end()||items[i]==1)
			{
				items[i] = 0;
			}
			else
			{
				items[i]--;
			}
			return items[i];
		}
		void empty_items()
		{
			items.clear();
		}
};

class bag : inventory
{
	friend class boost::serialization::access;
	int capacity;
	int held;
	template<class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		// serialize base class information
		ar & boost::serialization::base_object<inventory>(*this);
		// serialize new variables
		ar & capacity;
		ar & held;
	}
	public:
		bag(const int c){
			capacity = c;
		}
		int add_item(string i)
		{
			if(held<capacity)
			{
				held++;
				return inventory::add_item(i);
			}
			return -1;
		}
		int remove_item(string i)
                {
			if(held>0)
			{
				held--;
				return inventory::remove_item(i);
			}
			return -1;
		}
};

//saves serialized archive to a file
void save_inventory(const inventory &s, const char * filename)
{
	ofstream ofs(filename);
	boost::archive::text_oarchive oa(ofs);
	//serialize(oa, 1)
	oa << s;
}


//load serialized archive to a file
void load_inventory(inventory &s, const char * filename)
{
        ifstream ifs(filename);
        boost::archive::text_iarchive ia(ifs);
	//serialize(oa, 1)
        ia >> s;
}

int main()
{
	
}
