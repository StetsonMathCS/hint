#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
/*if saving to xml
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
*/

//for extended classes
#include <boost/serialization/base_object.hpp>
//each of the stl containers have a file such as list.hpp, vector.hpp, set.hpp
#include <boost/serialization/map.hpp>
#include <boost/serialization/string.hpp>
using namespace std;

//non member serialization method
namespace boost {
namespace serialization {

	template<class Archive>
	void serialize(Archive & ar, vector<map<string, map<string, string>>>& hints, const unsigned int version)
	{
		ar & hints;
	}
}
}

//saves serialized archive to a file
void save_hints(const vector<map<string, map<string, string>>>& hints)
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
void load_hints(vector<map<string, map<string, string>>>& hints)
{
        string homedir = string(getenv("HOME"))+"\\hints.txt";
	ifstream ifs(homedir.c_str());
        //if xml, boost::archive::xml_iarchive ia(ifs);
	boost::archive::text_iarchive ia(ifs);
	//serialize(oa, 1)
        ia >> hints;
}
int main()
{}
