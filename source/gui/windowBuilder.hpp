//windowBuilder

#ifndef SLIZERZ_01_WINDOW_BUILDER_01_HPP
#define SLIZERZ_01_WINDOW_BUILDER_01_HPP


#include "gui_components_02.hpp"
#include "im_gui_modifed_backends.hpp"


enum Degree_Colour
{
 DARK_GREEN_03,
 MID_GREEN_02,
 LIGHT_GREEN_01,
 GREEN_YELLOW_00,
 YELLOW_00,
 RED_YELLOW_n00,
 LIGHT_RED_n01,
 MID_RED_n02,
 DARK_RED_n03
};



const ImColor Dark_Green_03(120,210,120);
const ImColor Mid_Green_02(10,210,86);
const ImColor Light_Green_01(12,50,12);
const ImColor Green_Yellow_00(100,130,5);
const ImColor Yellow_00(160,170,5);
const ImColor Red_Yellow_n00(130,100,5);
const ImColor Light_Red_n01(101,10,20);
const ImColor Mid_Red_n02(200,80,80);
const ImColor Dark_Red_n03(220,12,120);
const ImColor ERROR_COLOUR(100,100,100);



    



 extern const char* GUI_Symbols[];

class input_symbol_price_box{
    
     char buffer_symbol[20];
     float price_buffer;
     int e = 0;
      
    //conferm. button
     public : 
    void write();

};

class im_gui_window
{
    public : 
void  im_context_create()
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
    }

void io_gui_config(const im_gui_window_parmz& parmz)
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

void set_imgui_style()
{
      ImGui::StyleColorsDark();
}

void  im_set_backend_opengl(const GLFWwindow* window)
{
    im_backend.ImGui_ImplGlfw_Init_redux(window, true, GlfwClientApi_OpenGL);
        
    IM_ASSERT((int)strlen(im_backend.glsl_version) + 2 < IM_ARRAYSIZE(im_backend.g_GlslVersionString));
    strcpy(im_backend.g_GlslVersionString, im_backend.glsl_version);
    strcat(im_backend.g_GlslVersionString, "\n");
}

void viewporting()
{
    ImGuiIO& io = ImGui::GetIO();
    //...need window
    ImGui::UpdatePlatformWindows();
    ImGui::RenderPlatformWindowsDefualt();


}
};



struct price_alert_LED
{
 ImU32  status_col;

 std::string symbol_label{""};
 double price=0.0;
 std::string last_time{""}; 
 int count =0;
 
 
 glm::vec2 uv{0.0,0.0};
 GLuint64 texture_handle{0};


 void set_time(long d)
 {
 	last_time = std::ctime(&d);
 }

 void set_count(int in)
 {
 	count = in;
 }


};


template<typename... mixin>
struct price_alert_comp :  

	price_alert_LED LED; 
	

	price_alert_comp(std::string& in_sym, double in_price)
	{
		LED.price = in_price;
		LED.symbol_label = in_sym; 
        text = "Price_Alert";
		//LED.time= std::ctime(&date); 
    }

    ImU32 get_pice_alert_colour(Degree_Colour& in_dc, float alpha);
     void write();
     
};

#endif