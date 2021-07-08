//unittest_analytic_MCP


// g++ -std=c++20 -pg -fconcepts-ts -I../../3rd_party/binacpp/lib/libbinacpp/include -I../../3rd_party ut_ana_MCP.cpp ../analytic/analytic_MCP.cpp ../binace_contoler/binance_mgmt.cpp ../core/utilityz/locks.cpp ../core/price_point_cmder.cpp  -lcurl -lcrypto -lwebsockets -lbinacpp -ljsoncpp -lpthread 



#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wpragmas"                  // warning: unknown option after '#pragma GCC diagnostic' kind
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"      // warning: cast to pointer from integer of different size
#pragma GCC diagnostic ignored "-Wformat-security"          // warning: format string is not a string literal (potentially insecure)
#pragma GCC diagnostic ignored "-Wdouble-promotion"         // warning: implicit conversion from 'float' to 'double' when passing argument to function
#pragma GCC diagnostic ignored "-Wconversion"               // warning: conversion to 'xxxx' from 'xxxx' may alter its value
#pragma GCC diagnostic ignored "-Wmisleading-indentation"   // [__GNUC__ >= 6] warning: this 'if' clause does not guard this statement      // GCC 6.0+ only. See #883 on GitHub.
#endif


#include "../analytic/analytic_MCP.hpp"

#include <iostream>
#include <fstream>
#include <chrono>

//#define DEBUG_01


//const std::basic_string<char> MATIC_BUSD("MATICBUSD");


#include <thread>
#include <set>

void bussywork()
{
	std::set<double> someset;
	for(int i =0; i<1000;i++)
	{
		double  someval = i; 
		someval += someval*someval/4*6*2/37;
		someset.emplace(someval );
	}
}
int main(int argc, char** argv)
{


analytic_MCP an_proc;
	
std::thread* bback_thread;


bback_thread = new std::thread(an_proc.back_binace_oper);

std::cout <<"thread kicked off entring main loop\n";


///siumalte adding priceroof/floor
an_proc.mprice_cmder.create_price_floor(MATIC_BUSD,1.210);
an_proc.mprice_cmder.create_price_floor(MATIC_BUSD,1.230);
an_proc.mprice_cmder.create_price_floor(MATIC_BUSD,1.2210);

an_proc.mprice_cmder.create_price_roof(MATIC_BUSD,1.1);
an_proc.mprice_cmder.create_price_roof(MATIC_BUSD,1.3270);
an_proc.mprice_cmder.create_price_roof(MATIC_BUSD,1.22);

//check to do update?
//an_proc.cycle_prices_alerts_redux();
auto start01 = std::chrono::high_resolution_clock::now();
for(int i=0; i<2000; i++)
{
 
bussywork();
std::cout << "MAINTHREAD::bussyworkdone i=" << i << '\n';

	if(0==i%100) 
{
	std::cout <<"MAINTHREAD##-->testing alert sycle\n";
	an_proc.cycle_prices_alerts_redux();
}
		
if(i == 1500)
{
	std::cout <<"attemping shutdown... load atomic false\n";
	an_proc.back_binace_oper.keep_binance_runing.store(false);
}

}
auto end01 = std::chrono::high_resolution_clock::now();
    if (bback_thread->joinable())
    {
    	std::cout <<"joinable..n";
    	 bback_thread->join();
    }
   std::chrono::duration<double> diff = end01-start01;
	
	//std::cout 
std::ofstream myfile;
  myfile.open ("speeddata.txt",std::ios::out | std::ios::app );
  myfile << "::time_dif1::::" << diff.count() << '\n';
  myfile.close();
return 0;

}