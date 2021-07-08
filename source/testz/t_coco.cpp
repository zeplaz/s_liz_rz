//main.cpp

//g++ -std=c++20 -pg -fconcepts-ts -I../3rd_party/binacpp/lib/libbinacpp/include -I../3rd_party t_coco.cpp core/engine  binace_contoler/binance_mgmt.cpp core/utilityz/locks.cpp core/price_point_cmder.cpp core/utilityz/utilityz.cpp -lcurl -lcrypto -lwebsockets -lbinacpp -ljsoncpp -lpthread 

///new cmdline.b


#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wpragmas"                  // warning: unknown option after '#pragma GCC diagnostic' kind
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"      // warning: cast to pointer from integer of different size
#pragma GCC diagnostic ignored "-Wformat-security"          // warning: format string is not a string literal (potentially insecure)
#pragma GCC diagnostic ignored "-Wdouble-promotion"         // warning: implicit conversion from 'float' to 'double' when passing argument to function
#pragma GCC diagnostic ignored "-Wconversion"               // warning: conversion to 'xxxx' from 'xxxx' may alter its value
#pragma GCC diagnostic ignored "-Wmisleading-indentation"   // [__GNUC__ >= 6] warning: this 'if' clause does not guard this statement      // GCC 6.0+ only. See #883 on GitHub.
#endif

//#include "core/engine.hpp"

//#include "core/utilityz/enumz_et_defultz.hpp"
//#include "core/tasker.hpp"


#include <iostream>



#define DEBUG_01
//const std::basic_string<char> MATIC_BUSD("MATICBUSD");




int main(int argc, char** argv)
{

//engine m_engine;
//m_engine.ignition();

analytic_MCP an_proc;
	

return 0;

}