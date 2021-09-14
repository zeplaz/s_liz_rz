

/*	
		t_yahooF_curl

	tests for yahoo finace curl data collection
*/



#include "../yahoofinace/yf_curl.hpp"


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

 std::time_t result = std::time(nullptr);
Error_Rangler er;

y_spot test_spot(result, 3094,403.34,30.3, 39.02); 

fmt::print("SPOTINFO \n{} ",test_spot.to_string());


y_quote test_quotec("KPLT"); 
std::string raw_curl = test_quotec.get_quote(i5d,g5m); 

fmt::print("\ntestquotecurel complated \n ");

parser_quote pq; 

pq.take_raw(raw_curl); 


return 0;
}
