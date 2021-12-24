//sdl_window_imp.cpp
#include "SDL_window.hpp"
#include "../SL_ZER_namespace_def01.hpp"


void sdl_window_imp::render()

    {
    		SDL_Window* l_window = static_cast<SDL_Window*>(window->window_hanlde()); 

        glViewport(0, 0,window->frameportbuffer_width ,window->frameportbuffer_height);
        glClearColor(SL_ZER::CLEAR_COLOUR_GLM.x * SL_ZER::CLEAR_COLOUR_GLM.w,
        				   SL_ZER::CLEAR_COLOUR_GLM.y * SL_ZER::CLEAR_COLOUR_GLM.w,
        				   SL_ZER::CLEAR_COLOUR_GLM.z * SL_ZER::CLEAR_COLOUR_GLM.w, 
        				   SL_ZER::CLEAR_COLOUR_GLM.w);
        glClear(GL_COLOR_BUFFER_BIT);

        //call draw on render for widnow////

        //call dtaw on imgui/// 

          SDL_GL_SwapWindow(l_window);
    } 
long double sdl_window_imp::get_window_time_seconds()
{
	//return (long double)(SDL_GetTicks64()/1000);

	#warning "###->THIS SHOULD BE UPDATED TO SDL_GetTicks64 once SDL 2.0.18 is out!";
	return (long double)(SDL_GetTicks()/1000);
}
	

void sdl_window_imp::handleKeys( unsigned char key, int x, int y )
   {
    //Toggle quad

   }	

void sdl_window_imp::poll_events()
{
	SDL_PollEvent(&event);
            

   #ifdef DEBUG_02
   debug_window_event(&event);
   #endif

   if (event.type == SDL_WINDOWEVENT)
   {
      switch (event.window.event)
      {
         case SDL_WINDOWEVENT_RESIZED:
  	      {
  	         window->Resized = true; 
            window->if_resized();
            break;
  	      }
  	            
         case SDL_WINDOWEVENT_SIZE_CHANGED:
         {
            window->Resized = true; 
            window->if_resized();
            break;	
         }   
              
      }
   }
      if (event.type == SDL_QUIT)
         {window->shutdown_signa = true;}
   
      if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && 
          event.window.windowID == SDL_GetWindowID(static_cast<SDL_Window*>(window->window_hanlde())))
         {window->shutdown_signa= true;} 
}   


void sdl_window_imp::debug_window_event(const SDL_Event * event)
{

    if (event->type == SDL_WINDOWEVENT) {
        switch (event->window.event) {
        case SDL_WINDOWEVENT_SHOWN:
            SDL_Log("Window %d shown", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_HIDDEN:
            SDL_Log("Window %d hidden", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_EXPOSED:
            SDL_Log("Window %d exposed", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_MOVED:
            SDL_Log("Window %d moved to %d,%d",
                    event->window.windowID, event->window.data1,
                    event->window.data2);
            break;
        case SDL_WINDOWEVENT_RESIZED:
            SDL_Log("Window %d resized to %dx%d",
                    event->window.windowID, event->window.data1,
                    event->window.data2);
            break;
        case SDL_WINDOWEVENT_SIZE_CHANGED:
            SDL_Log("Window %d size changed to %dx%d",
                    event->window.windowID, event->window.data1,
                    event->window.data2);
            break;
        case SDL_WINDOWEVENT_MINIMIZED:
            SDL_Log("Window %d minimized", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_MAXIMIZED:
            SDL_Log("Window %d maximized", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_RESTORED:
            SDL_Log("Window %d restored", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_ENTER:
            SDL_Log("Mouse entered window %d",
                    event->window.windowID);
            break;
        case SDL_WINDOWEVENT_LEAVE:
            SDL_Log("Mouse left window %d", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_FOCUS_GAINED:
            SDL_Log("Window %d gained keyboard focus",
                    event->window.windowID);
            break;
        case SDL_WINDOWEVENT_FOCUS_LOST:
            SDL_Log("Window %d lost keyboard focus",
                    event->window.windowID);
            break;
        case SDL_WINDOWEVENT_CLOSE:
            SDL_Log("Window %d closed", event->window.windowID);
            break;
#if SDL_VERSION_ATLEAST(2, 0, 5)
        case SDL_WINDOWEVENT_TAKE_FOCUS:
            SDL_Log("Window %d is offered a focus", event->window.windowID);
            break;
        case SDL_WINDOWEVENT_HIT_TEST:
            SDL_Log("Window %d has a special hit test", event->window.windowID);
            break;
#endif
        default:
            SDL_Log("Window %d got unknown event %d",
                    event->window.windowID, event->window.event);
            break;
        }
    }
}
