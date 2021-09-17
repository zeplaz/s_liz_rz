

/*	
		t_yahooF_curl

	tests for yahoo finace curl data collection
*/



#include "../yahoofinace/yf_curl.hpp"
#include "../core/utilityz/errorhandler.hpp"

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wpragmas"                  // warning: unknown option after '#pragma GCC diagnostic' kind
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"      // warning: cast to pointer from integer of different size
#pragma GCC diagnostic ignored "-Wformat-security"          // warning: format string is not a string literal (potentially insecure)
#pragma GCC diagnostic ignored "-Wdouble-promotion"         // warning: implicit conversion from 'float' to 'double' when passing argument to function
#pragma GCC diagnostic ignored "-Wconversion"               // warning: conversion to 'xxxx' from 'xxxx' may alter its value
#pragma GCC diagnostic ignored "-Wmisleading-indentation"   // [__GNUC__ >= 6] warning: this 'if' clause does not guard this statement      // GCC 6.0+ only. See #883 on GitHub.
#endif



int main(int argc, char** argv)
{

	parser_quote_yah pq; 

	quote_yah testQu = pq.get_quote("KPLT",i1mo,g15m);

	fmt::print("numspots {}\n", testQu.num_spots());

return 0;
}
