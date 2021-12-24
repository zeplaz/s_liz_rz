//render


#include "render.hpp"

#include "glfw_windowBuilder.hpp"
#include "SDL_window.hpp"
#include "../../gui/imgui_controler.hpp"
#include "../engine.hpp"

#include "../SL_ZER_namespace_def01.hpp"

std::atomic<render_MCP*> render_MCP::instance;
std::mutex render_MCP::render_mutex;

	render_MCP* render_MCP::get_instance()
	{	
		if(SL_ZER::RUNTIME_FRAMWORK_SET == false)
		{
			#if defined (USE_GLFW)
			SL_ZER::win_framwork =	SL_ZER::WINDOW_FRAMWORK::GLFW;

			#elif defined (USE_SDL)
			SL_ZER::win_framework = SL_ZER::WINDOW_FRAMWORK::SDL;
			#endif		
		}	
	  
	  static render_MCP* sin = instance.load(std::memory_order_acquire);

	  if(!sin)
	  {
	  	std::lock_guard<std::mutex> render_lock(render_mutex);
	 	sin = instance.load(std::memory_order_relaxed);
	 	if(!sin)
	 	{
	 		sin = new render_MCP; 
	 		instance.store(sin,std::memory_order_release);  	
	 	}
	  }
	  
	  return sin; 
	}

void render_MCP::launch_imgui()
	{
		imgui_ctl = new imgui_controler();
		imgui_ctl->im_context_create();
		imgui_ctl->set_style();

		if(SL_ZER::win_framework == SL_ZER::WINDOW_FRAMWORK::GLFW)
		{
		 imgui_ctl->connect_glfw((GLFWwindow*)window_imp->window->window_hanlde(), imgui_ctl->mimgui_backend.glsl_version);
		}
		if(SL_ZER::win_framework == SL_ZER::WINDOW_FRAMWORK::SDL)
		{
			window_sdl* loc_win = static_cast<window_sdl*> (window_imp->window); 
			SDL_Window* sdl_win = static_cast<SDL_Window*> (loc_win->window_hanlde());
			int res = SDL_GL_MakeCurrent(sdl_win,loc_win->get_glcontext());
			#ifdef DEBUG_01
			fmt::print("##->launchumgui context result{}", res); 
			#endif
		 	imgui_ctl->connect_sdl(sdl_win,imgui_ctl->mimgui_backend.glsl_version);
		}
		

	}

void render_MCP::configure()
	{
		if(SL_ZER::win_framework == SL_ZER::WINDOW_FRAMWORK::GLFW)	
	  	window_imp = new glfw_window_imp;
	  
	 	else if(SL_ZER::win_framework== SL_ZER::WINDOW_FRAMWORK::SDL)
	  	window_imp = new sdl_window_imp;
	}

void render_MCP::shutdown_window()
{
	window_imp->window->shutdown(); 
}
void render_MCP::shutdown_gui()
{	
	
		if(SL_ZER::win_framework == SL_ZER::WINDOW_FRAMWORK::SDL)
		{
			    ImGui_ImplOpenGL3_Shutdown();
    			ImGui_ImplSDL2_Shutdown();
    			ImGui::DestroyContext();
		}
		if(SL_ZER::win_framework == SL_ZER::WINDOW_FRAMWORK::GLFW)
		{
			    ImGui_ImplOpenGL3_Shutdown();
    		//	ImGui_ImplGlfw_Shutdown();
   				ImGui::DestroyContext();
		}
	
}


ERRORCODE render_MCP::launch_main_window()
{	
	ERRORCODE co; 
	co = window_imp->window->init();
	
	if(co != NO_ERROR)
	return co; 

	#ifdef DEBUG_02 
	fmt::print("-##->render_MCP::launch_main_window()::window_imp->window->init(). DONE::NO_ERROR \n");
	#endif

	if(defaulted_window)
	{
	  co = window_imp->window->create_window(SL_ZER::DEFAULT_MAIN_VEWPORT_WIDTH,SL_ZER::DEFAULT_MAIN_VEWPORT_HIGHT,SL_ZER::MAIN_WINDOW_TITLE); 
	
	#ifdef DEBUG_01
	set_gl_debug_context();
	#endif
	}

	return co; 

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


void render_MCP::window_render()
{
	window_imp->render();
	window_imp->poll_events();
}

bool render_MCP::poll_window_shutdown() 
{
	return window_imp->window->shutdown_signa; 
}

void render_MCP::gui_draw()
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

void render::close_window_x(size_t index)
{
	 glfw_window* w_temp = gl_windows.at(index);

	 w_temp->shutdown();
	 delete w_temp; 
	 
}*/