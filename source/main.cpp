//main.cpp


#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wpragmas"                  // warning: unknown option after '#pragma GCC diagnostic' kind
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"      // warning: cast to pointer from integer of different size
#pragma GCC diagnostic ignored "-Wformat-security"          // warning: format string is not a string literal (potentially insecure)
#pragma GCC diagnostic ignored "-Wdouble-promotion"         // warning: implicit conversion from 'float' to 'double' when passing argument to function
#pragma GCC diagnostic ignored "-Wconversion"               // warning: conversion to 'xxxx' from 'xxxx' may alter its value
#pragma GCC diagnostic ignored "-Wmisleading-indentation"   // [__GNUC__ >= 6] warning: this 'if' clause does not guard this statement      // GCC 6.0+ only. See #883 on GitHub.
#endif

#include "core/engine.hpp"

#include <iostream>

int main(int argc, char** argv)
{

	engine m_engine;
	
	m_engine.ignition();

	if(m_engine.m_engine_status== Engine_Status::READY)
		m_engine.cycle();

	if(m_engine.m_engine_status == Engine_Status::SHUTDOWN)
	 {
		m_engine.shutdown();
	 }
	else
	 {
 		std::cerr <<"\n#->##TODO:::engine state not resloved" 
 		<< underlying_type(m_engine.m_engine_status) << '\n';
	 }		

return 0;

}