//gui_compents testing.

/*
#define IF_DEBUG() \
#ifndef DEBUG_01 \
#endif 
// ...
*/

// g++ -std=c++20 -fconcepts-ts -pg ut_gui_compoents_0_1.cpp

#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wpragmas"                  // warning: unknown option after '#pragma GCC diagnostic' kind
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"      // warning: cast to pointer from integer of different size
#pragma GCC diagnostic ignored "-Wformat-security"          // warning: format string is not a string literal (potentially insecure)
#pragma GCC diagnostic ignored "-Wdouble-promotion"         // warning: implicit conversion from 'float' to 'double' when passing argument to function
#pragma GCC diagnostic ignored "-Wconversion"               // warning: conversion to 'xxxx' from 'xxxx' may alter its value
#pragma GCC diagnostic ignored "-Wmisleading-indentation"   // [__GNUC__ >= 6] warning: this 'if' clause does not guard this statement      // GCC 6.0+ only. See #883 on GitHub.
#endif


#define DEBUG_01

//#include "../gui/gui_components.hpp"

#ifdef DEBUG_01

#include <iostream>
#include <fstream>

#endif 


int main(int argc, char** argv)
{






std::cout <<"shutingdown return 0";
return 0;

}