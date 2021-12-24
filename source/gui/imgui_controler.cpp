
#include "imgui_controler.hpp"
#include <SDL2/SDL.h>


imgui_controler::~imgui_controler(){}

void imgui_controler::process_SDL(SDL_Event* in_e)
{
   ImGui_ImplSDL2_ProcessEvent(in_e); 
}


void imgui_controler::io_gui_config()
{
      
        ImGuiIO& gui_io = ImGui::GetIO();
        (void)gui_io;

        gui_io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        gui_io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

     
}

// for muli viewports.

void imgui_controler::update_viewporting()
{
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //...need window
  //  ImGui::UpdatePlatformWindows();
  //  ImGui::RenderPlatformWindowsDefualt();
}

void imgui_controler::connect_sdl(SDL_Window* window, const char* glsl_version)
{  
 SDL_GLContext gl_context  = SDL_GL_GetCurrentContext();
    
    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

void imgui_controler::connect_glfw(GLFWwindow* window, const char* glsl_version)
{
    glfw_ctrler.ImGui_ImplGlfw_Init_redux(window, true,GlfwClientApi_OpenGL);
    ImGui_ImplOpenGL3_Init(glsl_version);

}

unsigned int& imgui_controler::operator++() noexcept 
{
    num_widgets_alive++;
    return num_widgets_alive; 
}

unsigned int& imgui_controler::operator--() noexcept
{
    num_widgets_alive--;
    
    if(num_widgets_alive==0)
        a_widget_is_active = false; 

    return num_widgets_alive; 
}
unsigned int imgui_controler::operator--(unsigned int )
{

}
unsigned int imgui_controler::operator++(unsigned int)
{

}