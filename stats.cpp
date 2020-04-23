#include <iostream>
#include <string>
#include "stats.h"
#include <ctime>
#include <vector>

Stats::Stats(const string hintType, const string textType){
	time_t now = time(0);
	char* dt = ctime(&now);
	if (hintType.compare("search")){
		this->search = hintType;
	}else{
		this->tags = hintType;
	}
	this->textSearch = textType;
	myMap[hintType][textType] = dt;
	total[hintType][textType] += 1;
}

string Stats::getTextSearch() const{
	return textSearch;
}

int Stats::totalUse() const {
	return value;
}
