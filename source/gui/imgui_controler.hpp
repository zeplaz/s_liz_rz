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

#include "im_gui_modifed_backends.hpp"
#include "imgui_impl_sdl.h"


class imgui_controler
{
  imgui_glfw_ctler glfw_ctrler;

  bool a_widget_is_active = false; 
  unsigned int num_widgets_alive = 0; 

public : 
~imgui_controler(); 
imgui_backend mimgui_backend;    

inline void  im_context_create()
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
    }

inline void set_style()
{
      ImGui::StyleColorsDark();
}

inline unsigned int get_num_widgets()
{
    return num_widgets_alive; 
}

inline bool are_widgets_active()
{
return a_widget_is_active; 
}

inline void set_widgets_active()
{
    a_widget_is_active = true; 
} 

inline void set_widgets_closed()
{
    a_widget_is_active = false; 
}

unsigned int& operator++() noexcept;
unsigned int& operator--() noexcept;

unsigned int operator--(unsigned int);
unsigned int operator++(unsigned int);



void io_gui_config();

void update_viewporting();

void connect_sdl(SDL_Window* window, const char* glsl_version);

void connect_glfw(GLFWwindow* window, const char* glsl_version);

void process_SDL(SDL_Event* in_e); 

};




#endif