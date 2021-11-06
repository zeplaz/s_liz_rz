/*

//render

*/

#ifndef SLAZERZ_01_RENDER_MCP_001_HPP
#define SLAZERZ_01_RENDER_MCP_001_HPP






/*
switch to select glfw or sdl

#if defined (USE_GLFW)

#elif defined (USE_SDL)

#endif
*/
#define USE_SDL
//#define USE_GLFW


#include "base_window.hpp"
#include "../utilityz/errorhandler.hpp"



//forward deleclrations
class engine;


struct render_MCP
{

	#if defined (USE_GLFW)
	WINDOW_FRAMWORK win_framework = WINDOW_FRAMWORK::GLFW;

	#elif defined (USE_SDL)
	WINDOW_FRAMWORK win_framework = WINDOW_FRAMWORK::SDL; 
	#endif

	base_window* gl_window;

	render() = delete;
	render(engine& eng) : mengine(eng)
	{
	  #if defined (USE_GLFW)
	  gl_window = new window_glfw;
	  
	  #elif defined (USE_SDL)
	  gl_window = new window_sdl;
	  #endif
	}
	
	engine*  mengine = nullptr;

	ERRORCODE launch_main_window();

	void frame_write();

	bool display();

	void shutdown();

	void set_gl_debug_context(); 

};




#endif
