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
//these are what it keep hold of the data
static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

int answer(const char* url)
{

	//initiating the curl
	CURL *curl;
	CURLcode result;
	curl = curl_easy_init();

	if(curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, (url)); //This URL would need to be Malleable

		//follow URLS
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

		//sets a waiting time before it times out waiting for a response form the website
		curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10);

		//decodes weird charcters
		curl_easy_setopt(curl, CURLOPT_ACCEPT_ENCODING, "gzip");

		//Sends data to a fucntion i can access
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

		//actually getting the data
		result = curl_easy_perform(curl);

		//making sure that the curl is ok and worked right
		if(result != CURLE_OK)
		{
			cout << curl_easy_strerror(result) << endl;
			return  1;
		}

		//making that the website gave info 
		int httpCode(0);
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &httpCode);	
		curl_easy_cleanup(curl);

		//if website worked it will be equal to 200
		if(httpCode == 200)
		{
			//parseing data that we read in
			json data = json::parse(readBuffer);
			json newdata = data["items"];
			data = newdata[0];
			if(data["body"] != NULL)
			{
				newdata = data["body"];	//If this ends here then one should recive the answer back
				return  newdata;
			}
			else	//answer not found in first index of array checking the nex two
			{
				int flag = 0;

				for(int i = 1; i < 3; i++)
				{

					//checking second and third arrays for an accepted answer
					data = newdata[i];				
					if(data["body"] != NULL)
					{

						newdata = data["body"];
						return newdata;

					}


					//Flag is checking only three times for a valid answer if no valid answer then it terminates program
					flag++;
				}
				//seeing if we got a valid answer or not from one of the other indexes
				if(flag == 2)
				{
					cout << "Unable to locate answer" << endl;
					return  1;	
				}
			}
		}

		//This Happens If URL Fails to get info	
		else
		{
			cout << "URL FAILED TO LOAD" << endl;
			return  1;
		}
	}
	//if we got here then curl failed to iniitlaize
	cout << "Request Failed CURL not TRUE" << endl;
	return  0;
}

