//render


#include "render.hpp"
#include <iostream>    

void startup()
{
	#ifdef DEBUG_01
	set_debug_context();
	#endif
	start_main_window();
}

void start_main_window()
{
	mwindows_MGMT.create_new_window(DEFAULT_MAIN_VEWPORT_WIDTH,DEFAULT_MAIN_VEWPORT_HIGHT,true);
}

bool display()
{


}

void shutdown()
{

}









/*
void render::setup_window()
{

	glfw_window* win = new glfw_window();

	win.setup_contex();

	gl_windows.insert_rv(win);

}
*/
/*
void render::shutdown()
{		
	 	for(auto ittr = gl_windows.begin(); ittr != gl_window.end(); ittr++)
	 	{
	 		ittr->shutdown();
	 		delete *ittr;

	 	}
	 	gl_window.clear();
		glfwTerminate();
}



void render::close_window_x(size_t index)
{
	 glfw_window* w_temp = gl_windows.at(index);

	 w_temp->shutdown();
	 delete w_temp; 
	 
}*/