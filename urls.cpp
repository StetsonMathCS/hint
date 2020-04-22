#include <stdio.h>
#include "curl/curl.h"


int main()
{
	CURL* curl = curl_easy_init();
	if(!curl)
	{
		fprintf(stderr, "curl failure");
		return 0;
	}

	CURLcode res = CURLE_OK;
	if((res = curl_easy_setopt(curl, CURLOPT_URL, "https://stackoverflow.com/questions/61355433/how-to-get-stack-overflow-data-with-url-demonstrate-c-url-handlingi")) != CURLE_OK)
	{
		fprintf(stderr, curl_easy_strerror(res));
		return 1;
	}
	if((res = curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L)) != CURLE_OK)
	{
		fprintf(stderr, curl_easy_strerror(res));
		return 1;

	}
	if((res = curl_easy_perform(curl)) != CURLE_OK)
	{
		fprintf(stderr, curl_easy_strerror(res));
		return 1;
	}

	curl_easy_cleanup(curl);
	return 0;
}
