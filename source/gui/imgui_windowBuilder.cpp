
#include "imgui_windowBuilder.hpp"


void im_gui_window::io_gui_config(const im_gui_window_parmz& parmz)
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