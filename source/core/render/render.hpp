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

#include <memory>
#include <mutex>


//forward deleclrations
class engine;
class imgui_controler; 

struct render_MCP
{	

	protected : 
	render_MCP() = default;
	render_MCP(const render_MCP&) = delete; 
	render_MCP& operator=(const render_MCP&) = delete; 
	render_MCP(render_MCP&&) = delete;
	render_MCP& operator=(render_MCP&&) = delete; 

	engine*  mengine = nullptr;
	abstract_window_implmentor* window_imp = nullptr;
	imgui_controler* imgui_ctl = nullptr;
	
	static std::atomic<render_MCP*> instance;
    static std::mutex render_mutex;
	  
	public : 

	inline void set_engine(engine& eng) 
	{
		mengine = &eng;
	}  
	
	static render_MCP* get_instance();

	void configure();

	ERRORCODE launch_main_window();

	void frame_write();

	bool display();

	void shutdown();

	void set_gl_debug_context(); 

	void launch_imgui();

	void window_render();

	void gui_draw(); 
	
	void draw(); 


};


	



#endif
