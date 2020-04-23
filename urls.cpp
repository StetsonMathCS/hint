#include <stdio.h>
#include "curl/curl.h"
#include "json.hpp"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
using json = nlohmann::json;


namespace
{
	size_t callback(
			const char* in,
			size_t size,
			size-t num,
			string* out)
	{
		const size_t totalBytes(size *num);
		out->append(in, totalBytes);
		return totalBytes;
	}
}

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
		curl_easy_setopt(curl, CURLOPT_URL, "https://api.stackexchange.com/2.2/search?order=desc&sort=activity&intitle={question}&site=stackoverflow&filter=!BHMIbze.x2vCH_S4H0ZisKe_lF0yCi");

		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

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

			json jsonData;
			json jsonReader;
		}



	}
	return 0;



}
