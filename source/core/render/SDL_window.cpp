

//window_sdl.cpp
#include "SDL_window.hpp"


	 void sdl_window_imp::render()

    {
    		SDL_Window* l_window = static_cast<SDL_Window*>(window->window_hanlde()); 

        glViewport(0, 0,window->frameportbuffer_width ,window->frameportbuffer_height);
        glClearColor(CLEAR_COLOUR_GLM.x * CLEAR_COLOUR_GLM.w, CLEAR_COLOUR_GLM.y * CLEAR_COLOUR_GLM.w, CLEAR_COLOUR_GLM.z * CLEAR_COLOUR_GLM.w, CLEAR_COLOUR_GLM.w);
        glClear(GL_COLOR_BUFFER_BIT);

        //call draw on render for widnow////

        //call dtaw on imgui/// 

          SDL_GL_SwapWindow(l_window);
    } 


window_sdl::~window_sdl()
{
	shutdown();
}

void window_sdl::if_resized()
    {
    	SDL_Rect rec; 
    	SDL_RenderGetViewport(gRenderer, &rec);

    	frameportbuffer_width = rec.w;
    	frameportbuffer_height= rec.h;
    	Resized = false; 
    }    

ERRORCODE window_sdl::init()
{	

	ERRORCODE ec; 

	  frameportbuffer_width = DEFAULT_MAIN_VEWPORT_WIDTH;
     frameportbuffer_height= DEFAULT_MAIN_VEWPORT_HIGHT; 

  	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0)
	{
	   	printf("Error: %s\n", SDL_GetError());
       	return SDL_FAILED;
   	}

   	else
   	{    
    	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
    	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    	
    	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    	#ifdef DEBUG_01
    	this->set_context_flag(SDL_GL_CONTEXT_DEBUG_FLAG);
    	#endif
    	
    	  
    	ec = this->create_window(frameportbuffer_width, frameportbuffer_height,"MAIN-window SDL");	

        //Use Vsync
		if( SDL_GL_SetSwapInterval( 1 ) < 0 )
		{
		fmt::print("\nWarning: Unable to set VSync! SDL Error:{}\n",SDL_GetError());
		}
		 SDL_GL_MakeCurrent(gWindow, gl_context);
		
		 #ifdef DEBUG_01
  		 fmt::print("\n##->ERROR CODE create_window::{}\n", error_to_string(ec));
 		 #endif

 		 if(ec != NO_ERROR)
 		 return ec; 
	}

		ec = SL_ZER::glew_check();

	return ec; 
}

ERRORCODE window_sdl::create_window(int width, int hight, std::string title)
   {
      gWindow = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, hight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
		if( gWindow == nullptr)
		{
			fmt::print("\nWindow could not be created! SDL Error:{}\n", SDL_GetError());
			return SDL_WINDOW_FAIL; 
		}

		SDL_Renderer *gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	    if (gRenderer == nullptr) 
	    {
        fmt::print("SDL_CreateRenderer Error:{}\n",SDL_GetError());
        return SDL_RENDER_FAIL;
    	}

    	ERRORCODE ec = this->setup_context(); 
    	if(ec != NO_ERROR)
    	 return ec;

    	gl_context = SDL_GL_CreateContext( gWindow );
			if( gl_context == NULL )
			{
				fmt::print( "OpenGL context could not be created! SDL Error:{}\n", SDL_GetError());
				return SDL_CONTEXT_FAIL;
			}

			SDL_SetWindowResizable(gWindow,
                            SDL_TRUE);
			return NO_ERROR; 
    }


ERRORCODE window_sdl::setup_context()
 {
    glewExperimental = GL_TRUE; 
    GLenum glewError = glewInit();
    
    #ifdef DEBUG_01
    fmt::print("\n-->window_sdl::setup_context::|glew_code::{}\n", glewError);
   	#endif

    if( glewError != GLEW_OK )
	{
	    fmt::print("\n#####->Error initializing GLEW!{}\n", glewGetErrorString( glewError));
	    return GLEW_FAIL; 
	}
       
    fmt::print("OpenGL{}, GLSL{}\n", glGetString(GL_VERSION), glGetString(GL_SHADING_LANGUAGE_VERSION));

    glViewport( 0, 0, frameportbuffer_width, frameportbuffer_height );
   

    return NO_ERROR; 
   }

void window_sdl::shutdown()
{
	SDL_DestroyRenderer(gRenderer);
   SDL_DestroyWindow(gWindow);
   SDL_GL_DeleteContext(gl_context);
   gWindow = nullptr; 
   gRenderer = nullptr; 

   SDL_Quit();

    /* Quit program */
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
