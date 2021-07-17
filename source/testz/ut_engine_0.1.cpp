//unittest/engine.

/*
g++ -std=c++20 -pg -fconcepts-ts

--//opengl and gui --
-I../../3rd_party/imgui/backends -I../../3rd_party -I../../3rd_party/imgui  \
ut_renderer_0_1.cpp ../core/render.cpp ../core/opengl_utility.cpp  ../gui/gui_MCP.cpp \
../../3rd_party/imgui/imgui.cpp ../../3rd_party/imgui/imgui_draw.cpp ../../3rd_party/imgui/imgui_tables.cpp ../../3rd_party/imgui/imgui_widgets.cpp \
../../3rd_party/imgui/backends/imgui_impl_opengl3.cpp \
 -lcurl -lcrypto -lwebsockets -lbinacpp -ljsoncpp -lpthread -lGLEW -lglfw -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl 


---THE an_proc//----
-I../../3rd_party/binacpp/lib/libbinacpp/include /
-I../../3rd_party ut_ana_MCP.cpp ../analytic/analytic_MCP.cpp ../binace_contoler/binance_mgmt.cpp/
 ../core/utilityz/locks.cpp ../core/price_point_cmder.cpp /
  -lcurl -lcrypto -lwebsockets -lbinacpp -ljsoncpp -lpthread 

 */
#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wpragmas"                  // warning: unknown option after '#pragma GCC diagnostic' kind
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"      // warning: cast to pointer from integer of different size
#pragma GCC diagnostic ignored "-Wformat-security"          // warning: format string is not a string literal (potentially insecure)
#pragma GCC diagnostic ignored "-Wdouble-promotion"         // warning: implicit conversion from 'float' to 'double' when passing argument to function
#pragma GCC diagnostic ignored "-Wconversion"               // warning: conversion to 'xxxx' from 'xxxx' may alter its value
#pragma GCC diagnostic ignored "-Wmisleading-indentation"   // [__GNUC__ >= 6] warning: this 'if' clause does not guard this statement      // GCC 6.0+ only. See #883 on GitHub.
#endif


#include "../core/render.hpp"
#include "../gui/gui_MCP.hpp"  
#include "imgui_impl_opengl3.h"
#include "../core/engine.hpp"

int main(int argc, char** argv)
{

	engine mengine; 
    mengine.ignition();
    mengine.load_testz_systems();

    std::cout << "\n--->> main about to cycle\n";
    mengine.cycle();

return 0;

}
