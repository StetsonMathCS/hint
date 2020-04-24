#include <stdio.h>
#include <stdlib.h>
#include "curl/curl.h"
#include <string>
#include <iostream>
#include <fstream>
#include "json/json.h"
#include "json.hpp"
#include <unistd.h>
using json = nlohmann::json;
using namespace std;

static std::string readBuffer;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

int main()
{
	//thsi is the input from the user
	//	string worda, wordb;
	//	cout << "Please Enter your Question Using EXACTLY 2 Words" << endl;
	//	cin >> worda >> wordb;
	//	string question = worda + "%20" + wordb;
	//	cout << question;	

	//initiating the curl
	CURL *curl;
	CURLcode result;
	curl = curl_easy_init();

	if(curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, ("https://api.stackexchange.com/2.2/search?order=desc&sort=relevance&intitle=close%20vim&site=stackoverflow&filter=!)8aCqWxCWk*)CTW"));

		//follow URLS
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

		//sets a waiting time before it times out waiting for a response form the website
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

		//decodes weird charcters
		curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "gzip");

		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

		//actually getting the data
		result = curl_easy_perform(curl);

		//making sure that the curl is ok and worked right
		if(result != CURLE_OK)
		{
			cout << curl_easy_strerror(result) << endl;
			return 1;
		}

		//making that the website gave info 
		int httpCode(0);
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);	
		curl_easy_cleanup(curl);

		//if website worked it will be equal to 200
		if(httpCode == 200)
		{
			cout << "Sucessful Response From URL" << endl;
			cout << readBuffer << endl;
			json data = json::parse(readBuffer);
			cout << data[anwser_id] << endl;
		}
	}
	return 0;
}
