
#ifndef SLIZERZ_01_SDL_WINDOW_BUILDER_01_HPP
#define SLIZERZ_01_SDL_WINDOW_BUILDER_01_HPP

#include <SDL2/SDL.h>

#include "base_window.hpp"
#include "opengl_utility.hpp"


/*
SDL_SetRenderDrawColor(renderer, r, g, b, a);
*/

struct window_sdl : public base_window
{   
    friend struct sdl_window_imp; 
    
	protected : 

    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;
    SDL_GLContext gl_context;

    public : 

    ~window_sdl();

     ERRORCODE init() override;
	 ERRORCODE setup_context()override; 
     ERRORCODE create_window(int width, int hight, std::string title) override; 

     void shutdown() override;

     inline  SDL_GLContext get_glcontext()
     {
        return gl_context;
     }   

    inline void* window_hanlde() override
    {
        return gWindow; 
    }

    void if_resized() override; 


    inline void set_context_flag(int in_context_flag)
    {
        int contextFlags = 0;
        SDL_GL_GetAttribute(SDL_GL_CONTEXT_FLAGS, &contextFlags);
        contextFlags |= in_context_flag; 
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, contextFlags);
    }
};


struct sdl_window_imp : public abstract_window_implmentor
{

  friend class base_window; 
  friend class window_sdl; 
    SDL_Event event; 

    //Window focus
    bool mMouseFocus;
    bool mKeyboardFocus;
    bool mFullScreen;
    bool mMinimized;
    bool mShown;

    sdl_window_imp()
    {
        window = new window_sdl; 
    }

    void handleKeys( unsigned char key, int x, int y );

    void poll_events(); 
    
    void render() override; 

    void debug_window_event(const SDL_Event * event);
    
    long double get_window_time_seconds() override; 

};

#endif