
//template <template<typename>... mixinz>
//struct gui_compoent : public Mixinz<gui_compoent>...  
#ifndef SLIZERZ_01_IM_GUI_COMPOENTS_02_01_HPP
#define SLIZERZ_01_IM_GUI_COMPOENTS_02_01_HPP

#include "../core/opengl_utility.hpp"

#include <forward_list>


enum gui_object
{

};


struct gui_button
{

};

template<typename... mixinz>
struct gui_window : mixinz .. 
{

};

struct componet
{
    int id;
    std::string name;

};  
struct gui_window_parmz
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

struct gui_compoent_paramz
{	
	int id; 
	std::string title = ""; 
	bool has_text;
	bool has_label;
	bool remain_open = true;
	
	std::string text; 
	
};










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




#endif