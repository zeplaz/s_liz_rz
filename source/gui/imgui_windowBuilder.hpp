//windowBuilder

#ifndef SLIZERZ_01_IMGUI_WINDOW_BUILDER_01_HPP
#define SLIZERZ_01_IMGUI_WINDOW_BUILDER_01_HPP



/*
    ImDrawFlags_None                        = 0,
    ImDrawFlags_Closed                      = 1 << 0, // PathStroke(), AddPolyline(): specify that shape should be closed (Important: this is always == 1 for legacy reason)
    ImDrawFlags_RoundCornersTopLeft         = 1 << 4, // AddRect(), AddRectFilled(), PathRect(): enable rounding top-left corner only (when rounding > 0.0f, we default to all corners). Was 0x01.
    ImDrawFlags_RoundCornersTopRight        = 1 << 5, // AddRect(), AddRectFilled(), PathRect(): enable rounding top-right corner only (when rounding > 0.0f, we default to all corners). Was 0x02.
    ImDrawFlags_RoundCornersBottomLeft      = 1 << 6, // AddRect(), AddRectFilled(), PathRect(): enable rounding bottom-left corner only (when rounding > 0.0f, we default to all corners). Was 0x04.
    ImDrawFlags_RoundCornersBottomRight     = 1 << 7, // AddRect(), AddRectFilled(), PathRect(): enable rounding bottom-right corner only (when rounding > 0.0f, we default to all corners). Wax 0x08.
    ImDrawFlags_RoundCornersNone            = 1 << 8, // AddRect(), AddRectFilled(), PathRect(): disable rounding on all corners (when rounding > 0.0f). This is NOT zero, NOT an implicit flag!
    ImDrawFlags_RoundCornersTop             = ImDrawFlags_RoundCornersTopLeft | ImDrawFlags_RoundCornersTopRight,
    ImDrawFlags_RoundCornersBottom          = ImDrawFlags_RoundCornersBottomLeft | ImDrawFlags_RoundCornersBottomRight,
    ImDrawFlags_RoundCornersLeft            = ImDrawFlags_RoundCornersBottomLeft | ImDrawFlags_RoundCornersTopLeft,
    ImDrawFlags_RoundCornersRight           = ImDrawFlags_RoundCornersBottomRight | ImDrawFlags_RoundCornersTopRight,
    ImDrawFlags_RoundCornersAll             = ImDrawFlags_RoundCornersTopLeft | ImDrawFlags_RoundCornersTopRight | ImDrawFlags_RoundCornersBottomLeft | ImDrawFlags_RoundCornersBottomRight,
    ImDrawFlags_RoundCornersDefault_        = ImDrawFlags_RoundCornersAll, // Default to ALL corners if none of the _RoundCornersXX flags are specified.
    ImDrawFlags_RoundCornersMask_           = ImDrawFlags_RoundCornersAll | ImDrawFlags_RoundCornersNone

*/


#include "gui_components_02.hpp"
#include "im_gui_modifed_backends.hpp"

#include "../core/utilityz/id_utilityz.hpp"


extern const char* GUI_Symbols[];

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

struct im_gui_window_parmz
    {
        bool move_from_title = true;
        bool is_docking = true;
        bool is_viewporting = false; 

        ImGuiWindowFlags im_win_flag = 0;

        
         bool no_titlebar = false;
         bool no_scrollbar = false;
         bool no_menu = false;
         bool no_move = false;
         bool no_resize = false;
         bool no_collapse = false;
         bool no_close = false;
         bool no_nav = false;
         bool no_background = false;
         bool no_bring_to_front = false;

          
        inline void set_window_flags(ImGuiWindowFlags& window_flags)
        {

        if (no_titlebar)        window_flags |= ImGuiWindowFlags_NoTitleBar;
        if (no_scrollbar)       window_flags |= ImGuiWindowFlags_NoScrollbar;
        if (!no_menu)           window_flags |= ImGuiWindowFlags_MenuBar;
        if (no_move)            window_flags |= ImGuiWindowFlags_NoMove;
        if (no_resize)          window_flags |= ImGuiWindowFlags_NoResize;
        if (no_collapse)        window_flags |= ImGuiWindowFlags_NoCollapse;
        if (no_nav)             window_flags |= ImGuiWindowFlags_NoNav;
        if (no_background)      window_flags |= ImGuiWindowFlags_NoBackground;
        if (no_bring_to_front)  window_flags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
        //if (no_close)           p_open = nullptr; // Don't pass our bool* to Begin
    }
    };


class im_gui_window
{
    public : 
void  im_context_create()
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
    }


void io_gui_config(const im_gui_window_parmz& parmz);

void set_imgui_style()
{
      ImGui::StyleColorsDark();
}



void viewporting()
{
    ImGuiIO& io = ImGui::GetIO();
    //...need window
    ImGui::UpdatePlatformWindows();
    ImGui::RenderPlatformWindowsDefualt();


}
};



#endif