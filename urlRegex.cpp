//Author: Cole Spitzer
//Date 05-01-20
//Purpose: To go through the map and add all of the answers to the Data Structure

#include "urls.cpp"

//What this does is get the URL from the myMap. Which we are stroing as hint,URL, answer
//it then runs it through the function answer
//this gives us back the answer from the function and we are setting that equal to mymap[hint][URL] = answer string from the answer function

int main(){
	for( map<string, map<string, string> > :: const_iterator ptr = myMap.begin(); ptr != myMap.end(); ptr++)
	{
		for (map<string,string> :: const_iterator eptr = ptr->second.begin(); eptr != ptr->second.end();eptr++)	
		{
			 myMap[ptr->first][eptr->first] = answer(eptr->first);

		}
	}
}
