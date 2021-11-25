

#ifndef SLIZERZ_01_IM_GUI_MODIFED_BACKENDZ_01_HPP
#define SLIZERZ_01_IM_GUI_MODIFED_BACKENDZ_01_HPP

#include "../core/render/opengl_utility.hpp"

#include "imgui.h"
#include "imgui_impl_opengl3.h"



enum GlfwClientApi
{
    GlfwClientApi_Unknown,
    GlfwClientApi_OpenGL,
    GlfwClientApi_Vulkan
};


class imgui_backend
{
   //     friend class gui_mgmt;
public: 
    
    inline static char*        glsl_version = "#version 460";
    inline static char         g_GlslVersionString[32] = "";
    inline static GLuint       g_FontTexture = 0;
    inline static GLuint       g_ShaderHandle = 0, g_VertHandle = 0, g_FragHandle = 0;
    inline static int g_AttribLocationTex = 0, g_AttribLocationProjMtx = 0;
    inline static int          g_AttribLocationPosition = 0, g_AttribLocationUV = 0, g_AttribLocationColor = 0;
    inline static unsigned int g_VboHandle = 0, g_ElementsHandle = 0;
    /*----*/


    inline  static GlfwClientApi        g_ClientApi = GlfwClientApi_Unknown;
    inline  static double               g_Time = 0.0;
    
    inline  static GLFWcursor*          g_MouseCursors[ImGuiMouseCursor_COUNT] = {};
    inline  static bool                 g_InstalledCallbacks = false;
    
        // Chain GLFW callbacks: our callbacks will call the user's previously installed callbacks, if any.
    inline  static bool                 g_MouseJustPressed[ImGuiMouseButton_COUNT] = {};

    inline  static GLFWmousebuttonfun   g_PrevUserCallbackMousebutton = NULL;
    inline  static GLFWscrollfun        g_PrevUserCallbackScroll = NULL;
    inline  static GLFWkeyfun           g_PrevUserCallbackKey = NULL;
    inline  static GLFWcharfun          g_PrevUserCallbackChar = NULL;

    friend struct im_gui_ctler; 
    
///endit..    

};

struct imgui_glfw_ctler
{
float  g_Time = 0.0;
 imgui_backend im_backend;

 void ImGui_ImplGlfw_UpdateMousePosAndButtons(GLFWwindow* g_Window);  
 void ImGui_ImplGlfw_NewFrame(GLFWwindow* Window);
 void ImGui_ImplGlfw_UpdateMouseCursor(GLFWwindow* g_Window);  

void ImGui_ImplGlfw_UpdateGamepads();
 
 bool ImGui_ImplGlfw_Init_redux(GLFWwindow* window, bool install_callbacks, GlfwClientApi client_api);

};



namespace SL_ZER
{   
    static void HelpMarker(const char* desc);
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






#endif