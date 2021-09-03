
//template <template<typename>... mixinz>
//struct gui_compoent : public Mixinz<gui_compoent>...  
#ifndef SLIZERZ_01_IM_GUI_COMPOENTS_02_01_HPP
#define SLIZERZ_01_IM_GUI_COMPOENTS_02_01_HPP

//#include "../core/opengl_utility.hpp"

//#include <forward_list>


#include <string>

enum gui_object
{

};


struct gui_button
{

};

template<typename... mixinz>
struct gui_window : mixinz... 
{

};

struct componet
{
    int id;
    std::string name;

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






#endif