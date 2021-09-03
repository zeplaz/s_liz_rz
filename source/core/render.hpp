/*

//render

*/

#ifndef SLAZERZ_01_RENDER_MCP_001_HPP
#define SLAZERZ_01_RENDER_MCP_001_HPP


#include <GLFW/glfw3.h>
#include "glfw_windowBuilder.hpp"
#include "../gui/gui_MCP.hpp"

constexpr size_t MAX_GLFW_WINDOWS = 5; 

class engine; 


struct render
{
//	render_gui_mgmt	gui_mgmt;
	//shader_program_mgmt shader_mgmt;

	render() = delete;
	render(engine& eng) : mengine(eng){}
 	

	engine*  mengine = nullptr; 
	windows_MGMT  mwindows_MGMT; 
	
	void startup();
	 
	void start_main_window();

	void frame_write();

	bool display();

	void shutdown();




	

};


struct gpu_opengl_handler
{


	/*
GLsync glFenceSync( 	GLenum condition,
  	GLbitfield flags);

	*/

	void synic_testing()
	{
			GLsync waiton = glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE,0);
	}
/*		ALREADY_SIGNALED                0x911A
        TIMEOUT_EXPIRED                 0x911B
        CONDITION_SATISFIED             0x911C
        WAIT_FAILED                     0x911D
*/
};


#endif