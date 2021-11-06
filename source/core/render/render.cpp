//render


#include "render.hpp"

#include "glfw_windowBuilder.hpp"
#include "SDL_window.hpp"

void render_MCP::shutdown()
{
	gl_window->shutdown(); 

}
render_MCP::render(engine& eng) : mengine(eng)
{
    #if defined (USE_GLFW)
    gl_window = new window_glfw;
	  
    #elif defined (USE_SDL)
    gl_window = new window_sdl;
    #endif
	}
	

ERRORCODE render_MCP::launch_main_window()
{
	gl_window->init(); 

	#ifdef DEBUG_01
	set_gl_debug_context();
	#endif
}



void render_MCP::set_gl_debug_context()
{
	GLint flags;
	glGetIntegerv(GL_CONTEXT_FLAGS, &flags);

if (flags & GL_CONTEXT_FLAG_DEBUG_BIT)
{
	fmt::print("\gl_debug_::debug iniaizled\n");
  
  glEnable(GL_DEBUG_OUTPUT);
  glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
  glDebugMessageCallback(glDebugOutput, nullptr);
  glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);


}
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