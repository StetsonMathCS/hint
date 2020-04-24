#include <stdio.h>
#include <stdlib.h>
#include "curl/curl.h"
#include <string>
#include <iostream>
#include <fstream>
#include "json.hpp"
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
		curl_easy_setopt(curl, CURLOPT_URL, ("https://api.stackexchange.com/2.2/search?order=desc&sort=relevance&intitle=close%20vim&site=stackoverflow&filter=!)8aCqWxCWk*)CTW")); //This URL would need to be Malleable

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
			json data = json::parse(readBuffer);
			json newdata = data["items"];
			data = newdata[0];
			if(data["accepted_answer_id"] != NULL)
			{
				newdata = data["accepted_answer_id"];
			}
			else
			{
				int flag = 0;
				for(int i = 1; i < 3; i++)
				{
					data = newdata[i];				//Need to Figure out how to really do Try/Catch in C++
					if(data["accepted_answer_id"] != NULL)
					{
						break;
					}
					flag++;


				}
				if(flag == 2)
				{
					return 0;	
				}	
			}

			CURL *curl;
			CURLcode result;
			curl = curl_easy_init();
			curl_easy_setopt(curl, CURLOPT_URL, ("https://api.stackexchange.com/2.2/answers/23249538?order=desc&sort=activity&site=stackoverflow&filter=!1zSk1ioD0vr4SZwW_vEX9"));	//If i can make these URLS Changeable
																								//We could Do lots with this!

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

		}
		else
		{
			cout << "URL FAILED TO LOAD" << endl;
			return 1;
		}
	}
	return 0;
}
