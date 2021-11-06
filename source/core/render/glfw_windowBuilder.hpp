


#ifndef SLIZERZ_01_GLFW_WINDOW_BUILDER_01_HPP
#define SLIZERZ_01_FKFW_WINDOW_BUILDER_01_HPP

#include "utilityz/id_utilityz.hpp"
#include "utilityz/errorhandler.hpp"

#include "opengl_utility.hpp"


//constexpr int DEFAULT_WINDOW_WIDTH  = 500;
//constexpr int DEFAULT_WINDOW_HIGHT  = 500;


class GLFWwindow; 
class GLEWContext; 

struct window_glfw
{   

//public params
    inline static bool Resized = false; 

 //   bool flag_collectable = false; 
   
    GLFWwindow* gWindow = nullptr; 
    GLEWContext* gContext = nullptr;
    
    private :
    
     int frameportbuffer_width;  
     int frameportbuffer_height;
    
    glm::mat4    m_m4Projection;
    glm::mat4    m_m4ViewMatrix;


    int lowleft_x=0;
    int lowleft_y=0;     

public: 
    //overied  fro base
    ~window_glfw();

    ERRORCODE init() override; 
    ERRORCODE setup_context() override;
    ERRORCODE create_window(int width, int hight, std::string title) override;
    void shutdown()override ;
    void render() override; 
    ERRORCODE  glew_check() override;
    void set_debug_context();

//
    int is_window_open();
    bool poll_to_close();

    void if_resized(); 


    
private: 
    
    void set_viewport_callback();
    void set_windowSize_callback();
    void set_framebuffer_callback();

};


#endif




