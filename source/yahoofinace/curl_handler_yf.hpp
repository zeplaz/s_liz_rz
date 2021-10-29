
#ifndef SLAZERZ_01_CURL_HANDLER_YF_001_HPP
#define SLAZERZ_01_CURL_HANDLER_YF_001_HPP

#include <string>
struct curl_handler
{

	std::string get_rawQuote(std::string symbol, int range, int granulity);

	inline static size_t writeCallback(char *content, size_t size, size_t nmemb, void *userdata)
		 {
	    // Append the content to user data
	    ((std::string*)userdata)->append(content, size * nmemb);

	    // Return the real content size
	    return size * nmemb;
	}

};

#endif
