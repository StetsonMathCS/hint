#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include <boost/archive/tmpdir.hpp>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include <boost/serialization/base_object.hpp>
#include <boost/serialization/utility.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/assume_abstract.hpp>
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
		int add_item(string i)
		{
			if(find(i)==items.end())
			{
				items[string]++;
			}
			else
			{
				items.insert(i,1);
			}
			return items[string];
		}
		int remove_item(string i)
                {
                        if(find(i)==items.end())
                        {
                                items[string]--;
                        }
			else
			{
                        	items.insert(i,0);
			}
			return items[string];
                }
		void empty_items()
		{}
};

//saves serialized archive to a file
void save_inventory(const bus_schedule &s, const char * filename)
{
	ofstream ofs(filename);
	boost::archive::text_oarchive oa(ofs);
	//serialize(oa, 1)
	oa << s;
}


//load serialized archive to a file
void load_inventory(const bus_schedule &s, const char * filename)
{
        ifstream ifs(filename);
        boost::archive::text_oarchive ia(ifs);
	//serialize(oa, 1)
        ia << s;
}

int main()
{
	
}
