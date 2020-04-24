#include <stdio.h>
#include <stdlib.h>
#include "curl/curl.h"
#include <string>
#include <iostream>
#include <fstream>
#include "json/json.h"
#include "json.hpp"
using json = nlohmann::json;
using namespace std;






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

	FILE* file = fopen("urls.txt", "w");
	if(curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, ("https://api.stackexchange.com/2.2/search?order=desc&sort=relevance&intitle=close%20vim&site=stackoverflow&filter=!)8aCqWxCWk*)CTW"));

		//follow URLS
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

		//sets a waiting time before it times out waiting for a response form the website
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

		//decodes weird charcters
		curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "gzip");

		curl_easy_setopt(curl, CURLOPT_WRITEDATA, file);

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
			ifstream ifile("urls.txt");

			cout << "Sucessful Response From URL" << endl;
			string line;

			if(ifile.is_open())
			{
				cout << "Attemting To Get Answer ID" << endl;
				while(getline(ifile, line))
				{
					cout << "Turninng File into JSON" << endl;
					stringstream s(line);
					json j_done = json::parse(s);
					
					
				}
			}




		}



	}
	return 0;



}
