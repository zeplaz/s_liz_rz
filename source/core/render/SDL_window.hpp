

#include <SDL2/SDL.h>
#include "opengl_utility.hpp"


/*
SDL_SetRenderDrawColor(renderer, r, g, b, a);

*/
struct window_sdl
{

	 private : 
    //Window data
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
    SDL_GLContext gContext;
    inline static bool Resized = false; 
    
    SDL_Event event;

        //Window focus
    bool mMouseFocus;
    bool mKeyboardFocus;
    bool mFullScreen;
    bool mMinimized;
    bool mShown;

	const char* glsl_version = "#version 450";

    int frameportbuffer_width;  
    int frameportbuffer_height;
    
    glm::mat4    m_m4Projection;
    glm::mat4    m_m4ViewMatrix;

    void if_resized()
    {
    	case SDL_WINDOWEVENT:
            if( {
            repaint = true;
            }
    }

    void render()
	    {

	    //begin imguirender..
	    	
	    glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        
        //ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        
        SDL_GL_SwapWindow(window);






    }
    
    ERRORCODE create_window(int width, int hight, std::string title)
    {
      	gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN );
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

    	gContext = SDL_GL_CreateContext( gWindow );
			if( gContext == NULL )
			{
				fmt::print( "OpenGL context could not be created! SDL Error:{}\n", SDL_GetError() );
				return SDL_CONTEXT_FAIL;
			}

			return NO_ERROR; 
    }


    void set_contex_flag(int in_context_flag)
    {
    	int contextFlags = 0;
		SDL_GL_GetAttribute(SDL_GL_CONTEXT_FLAGS, &contextFlags);
		contextFlags |= in_context_flag; 
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, contextFlags);
    }

   ERRORCODE setup_context()
 {
    glewExperimental = GL_TRUE; 
    GLenum glewError = glewInit();
    
    #ifdef DEBUG_01
    fmt::print("\n-->|glew_code::{}\n", glewError);
   	#endif

    if( glewError != GLEW_OK )
	{
	    fmt::print("\n#####->Error initializing GLEW!{}\n", glewGetErrorString( glewError));
	    return GLEW_FAIL; 
	}
       
    fmt::print("OpenGL{}, GLSL{}\n", glGetString(GL_VERSION), glGetString(GL_SHADING_LANGUAGE_VERSION));

    glViewport( 0, 0, SCREEN_WIDTH_DEFULT, SCREEN_HEIGHT_DEFULT );
   

    return NO_ERROR; 
   }


ERRORCODE init()
{	

	ERRORCODE ec; 

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
    	
    	ec = this->setup_context(); 
    	
    	if(ec == NO_ERROR)
    	ec = this->create_window();	

        //Use Vsync
		if( SDL_GL_SetSwapInterval( 1 ) < 0 )
		{
		fmt::print("\nWarning: Unable to set VSync! SDL Error:{}\n",SDL_GetError());
		}
		 SDL_GL_MakeCurrent(window, gl_context);
		}

	return ec; 
}

void handleKeys( unsigned char key, int x, int y )
{
	//Toggle quad
	if( key == 'q' )
	{
		
	}
}

void shutdown()
{
	SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(gWindow);
    SDL_GL_DeleteContext(gContext);

    SDL_Quit();

    /* Quit program */
}

};