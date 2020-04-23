#include <stdio.h>
#include "curl/curl.h"
#include "json.hpp"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
using json = nlohmann::json;

int main()
{
	//thsi is the input from the user
	string question;
	cout << "Please Enter your Question Using EXACTLY 2 Words" << endl;
	getline(cin, question);

	//initiating the curl
	CURL *curl;
	CURLcode result;
	curl = curl_easy_init();
	string url = "api.stackexchange.com/2.2/search?order=desc&sort=activity&intitle=" + question + "&site=stackoverflow&filter=!)8aCqWxCWk*)CTW";

	if(curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, ("api.stackexchange.com/2.2/search?order=desc&sort=activity&intitle={question}&site=stackoverflow&filter=!)8aCqWxCWk*)CTW"));
	
		//follow URLS
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		
		//sets a waiting time before it times out waiting for a response form the website
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

		//decodes weird charcters
		curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "gzip");

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




		}



	}
	return 0;



}
