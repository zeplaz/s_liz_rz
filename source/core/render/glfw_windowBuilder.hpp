


#ifndef SLIZERZ_01_GLFW_WINDOW_BUILDER_01_HPP
#define SLIZERZ_01_GLFW_WINDOW_BUILDER_01_HPP

#include "../utilityz/id_utilityz.hpp"
#include "../utilityz/errorhandler.hpp"

#include "opengl_utility.hpp"

#include "base_window.hpp"


class GLFWwindow; 
class GLEWContext; 

struct window_glfw : public base_window
{   
        
    GLFWwindow*  gWindow  = nullptr; 
    GLEWContext* gContext = nullptr;

    //overied  fro base
    ~window_glfw();

    ERRORCODE init() override; 
    ERRORCODE setup_context() override;
    ERRORCODE create_window(int width, int hight, std::string title) override;
    void shutdown()override ;
   

    void set_debug_context();

    inline void* window_hanlde() override
    {
        return gWindow; 
    }

    void if_resized() override; 
    
    protected: 
    
    void set_viewport_callback();
    void set_windowSize_callback();
    void set_framebuffer_callback();


};

struct glfw_window_imp : public abstract_window_implmentor
{   
    friend window_glfw; 

    glfw_window_imp()
    {
        window = new window_glfw; 
    }

    int lowleft_x=0;
    int lowleft_y=0;     

    void poll_events() override;

    int is_window_open(); 
    void render() override; 
    long double get_window_time_seconds() override; 

}; 

#endif




