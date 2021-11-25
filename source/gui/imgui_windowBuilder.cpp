
#include "imgui_windowBuilder.hpp"
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
    
/*
        gui_io.ConfigWindowsMoveFromTitleBarOnly = parmz.move_from_title;
 
        if(parmz.is_docking)
        {
              gui_io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; 
        }    
        
        if(parmz.is_viewporting)
        {
              gui_io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
        }

      
        gui_io.BackendRendererName  = "imgui_mofifed_opengl_4.X";
        gui_io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
        gui_io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
}

*/
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