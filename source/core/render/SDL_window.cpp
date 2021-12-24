

//window_sdl.cpp
#include "SDL_window.hpp"
#include "../SL_ZER_namespace_def01.hpp"



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
	


  	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER ) != 0)
	{
	   	printf("Error: %s\n", SDL_GetError());
       	return SDL_FAILED;
   }
   //fmt::print("ERROC???..")

  // SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
 // 	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
  //	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    	
  	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    	#ifdef DEBUG_01
    	this->set_context_flag(SDL_GL_CONTEXT_DEBUG_FLAG);
    	#endif

  	return NO_ERROR; 
	
   
}

ERRORCODE window_sdl::create_window(int width, int hight, std::string title)
   {   

   	ERRORCODE ec; 

   	frameportbuffer_width = width;
      frameportbuffer_height = hight; 

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

    	ec = this->setup_context(); 

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
		
		ec = SL_ZER::glew_check();
			
		return ec; 
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


