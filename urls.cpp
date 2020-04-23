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
	string question;
	cout << "Please Enter your Question" << endl;
	getline(cin, question);

	CURL *curl;
	CURLcode result;
	curl = curl_easy_init();

	if(curl)
	{

		//easy_curl_setopt is setting the options for my curl
		curl_easy_setopt(curl, CURLOPT_URL, "https://api.stackexchange.com/2.2/search?order=desc&sort=activity&intitle={question}&site=stackoverflow&filter=!)5IUN_bW2QoJ3.ftG)n_UX8Uuoty");

		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		
		//sets a waiting time before it times out waiting for a response form the website
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

//		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback);

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
