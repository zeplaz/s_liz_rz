
//template <template<typename>... mixinz>
//struct gui_compoent : public Mixinz<gui_compoent>...  
#ifndef SLIZERZ_01_IM_GUI_COMPOENTS_02_01_HPP
#define SLIZERZ_01_IM_GUI_COMPOENTS_02_01_HPP


#include <string>

enum class Gui_Object_Def
{ 
 confirm_button,
 submit_button,
 cancel_button,
 save_button,
 close_button

};


struct componet
{
    int id;
    std::string name;

};  

struct gui_button : public componet
{
	Gui_Object_Def button_type; 
	

};

template<typename... mixinz>
struct gui_windgets : public mixinz... 
{

};



struct gui_compoent_paramz
{	
	
	std::string title = ""; 
	bool has_text = false; 
	bool has_label = false;
	bool remain_open = true;
	
	std::string text; 
	
};






#endif