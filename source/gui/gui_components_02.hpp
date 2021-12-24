
//template <template<typename>... mixinz>
//struct gui_compoent : public Mixinz<gui_compoent>...  
#ifndef SLIZERZ_01_IM_GUI_COMPOENTS_02_01_HPP
#define SLIZERZ_01_IM_GUI_COMPOENTS_02_01_HPP


#include <string>
 #include <variant>

enum class Button_Type 
{ 
 confirm_button,
 submit_button,
 cancel_button,
 save_button,
 close_button

};

enum class Gui_widget_Type
{
	Text_PopUp,
	User_Text_Input
};


struct componet
{
    E_ID id; 
    std::string name;
};  



struct gui_compoent_paramz
{	
	
	std::string title = ""; 
	bool has_text = false; 
	bool has_label = false;
	bool remain_open = true;
	
	std::string text =""; 
	
};


struct gui_compoent : public compoent
{
	gui_compoent_paramz paramz; 
};

template<typename... mixinz>
struct gui_widgets : public  mixinz... 
{
	

};

struct gui_button : public gui_compoent 
{	
	Button_Type button_type; 
};

struct text_input: public gui_compoent 
{	
	std::string received_text; 
};





#endif