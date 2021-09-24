///curl_handler_yf


#include "yf_curl.hpp"

#include <curl/curl.h>


#include "../core/utilityz/errorhandler.hpp"

std::string curl_handler::get_rawQuote(std::string symbol, int range, int granulity)
{


		std::string url = query_chart_url+symbol + 
					      range_tag + ranges_period.at(range) + 
					      interval_tag + granualrity.at(granulity) + 
					      incator_timestamp;

			
		std::string responseBuffer;

		CURL* curl = curl_easy_init();
		
		if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());	

         curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
         curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);

            // Perform the request
            CURLcode res = curl_easy_perform(curl);

            #ifdef DEBUG_01
            const char *str = curl_easy_strerror( res );
            fmt::print("\n##-->CURLcode:: {}\n", str);
           // fmt::print("************responseBuffer:: {}\n *************************************\n",responseBuffer);
            #endif

            // Cleanup
            curl_easy_cleanup(curl);
    	}

    	return responseBuffer;
}
