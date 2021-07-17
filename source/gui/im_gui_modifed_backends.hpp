

#ifndef SLIZERZ_01_IM_GUI_BACKENDZ_01_HPP
#define SLIZERZ_01_IM_GUI_BACKENDZ_01_HPP

#include "../core/opengl_utility.hpp"

#include "imgui.h"

#include "imgui_impl_opengl3.h"

static void HelpMarker(const char* desc)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}

enum GlfwClientApi
{
    GlfwClientApi_Unknown,
    GlfwClientApi_OpenGL,
    GlfwClientApi_Vulkan
};

namespace SL_ZER
{   
    namespace callbacks
    {

    IMGUI_IMPL_API void     ImGui_ImplGlfw_MouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
    IMGUI_IMPL_API void     ImGui_ImplGlfw_ScrollCallback(GLFWwindow* window, double xoffset, double yoffset);
    IMGUI_IMPL_API void     ImGui_ImplGlfw_KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
    IMGUI_IMPL_API void     ImGui_ImplGlfw_CharCallback(GLFWwindow* window, unsigned int c);

    }
   
    namespace clip
    {
    static void        ImGui_ImplGlfw_SetClipboardText(void* user_data, const char* text);
    static const char* ImGui_ImplGlfw_GetClipboardText(void* user_data);
    }



}



class imgui_backend
{
        friend class gui_mgmt;
private: 
    
    inline static char*        glsl_version = "#version 450";
    inline static char         g_GlslVersionString[32] = "";
    inline static GLuint       g_FontTexture = 0;
    inline static GLuint       g_ShaderHandle = 0, g_VertHandle = 0, g_FragHandle = 0;
    inline static int          g_AttribLocationTex = 0, g_AttribLocationProjMtx = 0;
    inline static int          g_AttribLocationPosition = 0, g_AttribLocationUV = 0, g_AttribLocationColor = 0;
    inline static unsigned int g_VboHandle = 0, g_ElementsHandle = 0;
    /*----*/


    inline  static GlfwClientApi        g_ClientApi = GlfwClientApi_Unknown;
    inline  static double               g_Time = 0.0;
    
    inline  static GLFWcursor*          g_MouseCursors[ImGuiMouseCursor_COUNT] = {};
    inline  static bool                 g_InstalledCallbacks = false;


     void ImGui_ImplGlfw_UpdateGamepads();
     void ImGui_ImplGlfw_UpdateMouseCursor(GLFWwindow* g_Window);  
     void ImGui_ImplGlfw_UpdateMousePosAndButtons(GLFWwindow* g_Window);  

    public : 
    void ImGui_ImplGlfw_NewFrame(GLFWwindow* Window);
        // Chain GLFW callbacks: our callbacks will call the user's previously installed callbacks, if any.
    bool ImGui_ImplGlfw_Init_redux(GLFWwindow* window, bool install_callbacks, GlfwClientApi client_api);
    
    inline  static bool                 g_MouseJustPressed[ImGuiMouseButton_COUNT] = {};

    inline  static GLFWmousebuttonfun   g_PrevUserCallbackMousebutton = NULL;
    inline  static GLFWscrollfun        g_PrevUserCallbackScroll = NULL;
    inline  static GLFWkeyfun           g_PrevUserCallbackKey = NULL;
    inline  static GLFWcharfun          g_PrevUserCallbackChar = NULL;

    
///endit..    


};



#endif