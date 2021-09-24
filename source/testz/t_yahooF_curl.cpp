

/*	
		t_yahooF_curl

	tests for yahoo finace curl data collection
*/



#include "../yahoofinace/yf_curl.hpp"
#include "../yahoofinace/quote_requester.hpp"
#include "../core/utilityz/errorhandler.hpp"
#include <functional>
#include <thread>

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wpragmas"                  // warning: unknown option after '#pragma GCC diagnostic' kind
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"      // warning: cast to pointer from integer of different size
#pragma GCC diagnostic ignored "-Wformat-security"          // warning: format string is not a string literal (potentially insecure)
#pragma GCC diagnostic ignored "-Wdouble-promotion"         // warning: implicit conversion from 'float' to 'double' when passing argument to function
#pragma GCC diagnostic ignored "-Wconversion"               // warning: conversion to 'xxxx' from 'xxxx' may alter its value
#pragma GCC diagnostic ignored "-Wmisleading-indentation"   // [__GNUC__ >= 6] warning: this 'if' clause does not guard this statement      // GCC 6.0+ only. See #883 on GitHub.
#endif

#include <iostream>  

int main(int argc, char** argv)
{

//	parser_quote_yah pq; 
	thread_quote_worker quote_worker;
	quote_bank test_qutebank;
	std::shared_ptr<quote_bank> qb = std::make_shared<quote_bank>(test_qutebank);
	


	std::thread worker_yahoo(std::ref(quote_worker));
 

	 Q_Key request1 = quote_worker.q_requester.create_request(qb,"KPLT",i1mo,g15m);

	 

	for(int i=0; i<200;i++)
	{
		int fj = i*2/i;
		fj++;
		std::cout << "wasttime;\n";
	}
	std::string input; 
	
	quote_worker.q_requester.create_request(qb,"HUT",i1mo,g1d);
	std::cout << "addinput::";
	std::cin >> input;
	quote_worker.q_requester.create_request(qb,"KPLT",i1mo,g1h);
	quote_worker.q_requester.shutdown();
	worker_yahoo.join();

	



return 0;
}
