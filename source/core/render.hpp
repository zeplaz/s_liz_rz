///render


#ifndef SLAZERZ_01_RENDER_MCP_001_HPP
#define SLAZERZ_01_RENDER_MCP_001_HPP

#include "opengl_utility.hpp"
#include <string>  

constexpr int DEFAULT_WINDOW_HIGHT = 500;
constexpr int DEFAULT_WINDOW_WIDTH  = 500;

constexpr int MAIN_VEWPORT_HIGHT = 500;
constexpr int MAIN_VEWPORT_WIDTH  = 500;



struct render
{
//	render_gui_mgmt	gui_mgmt;
	//shader_program_mgmt shader_mgmt;
	GLFWwindow*     window;

	int setup_contex();

	inline void set_gui_api();

	void frame_write();

	bool display();

	void shutdown();
	

};


#endif