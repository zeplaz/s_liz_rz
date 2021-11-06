
#include "imgui_windowBuilder.hpp"

imgui_controler::~imgui_controler(){}

void imgui_controler::io_gui_config(const im_gui_window_parmz& parmz)
{
     ImGuiIO& gui_io = ImGui::GetIO();
        (void)gui_io;

        gui_io.ConfigWindowsMoveFromTitleBarOnly = parmz.move_from_title;
 
        if(parmz.is_docking)
        {
              gui_io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; 
        }    
        
        if(parmz.is_viewporting)
        {
              gui_io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
        }

        gui_io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
        //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

        gui_io.BackendRendererName  = "imgui_mofifed_opengl_4.5";
        gui_io.KeyMap[ImGuiKey_Delete] = GLFW_KEY_DELETE;
        gui_io.KeyMap[ImGuiKey_Backspace] = GLFW_KEY_BACKSPACE;
}



void imgui_controler::update_viewporting()
{
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //...need window
    ImGui::UpdatePlatformWindows();
    ImGui::RenderPlatformWindowsDefualt();
}

void imgui_controler::connect_sdl(SDL_Window* window, SDL_GLContext* gl_context, const char* glsl_version)
{
    ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
    ImGui_ImplOpenGL3_Init(glsl_version);
}

void imgui_controler::connect_glfw(GLFWwindow* window, const char* glsl_version)
{
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

}