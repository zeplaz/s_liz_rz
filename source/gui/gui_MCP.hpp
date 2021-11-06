//render_GUI_MCP
#ifndef SLAZERZ_01_RENDER_GUI_MCP_001_HPP
#define SLAZERZ_01_RENDER_GUI_MCP_001_HPP

////////////////////////////////////////////////////
#include <string>
#include <forward_list>
#include <functional>

#include <iostream>

#include "im_gui_modifed_backends.hpp"

#include "gui_components_02.hpp"

//#include "windowBuilder.hpp"

#include "../core/utilityz/enumz_et_defultz.hpp"


#include "extentions/text_combo_box.hpp"

enum class Show_GUI : uint32_t
{	
	NONE             =0x00,
	SHOW_MAIN_MENU   =0x01,
	SHOW_FULL_SCREEN =0x02


};

class gui_mgmt
{	
	
ImVec4 gui_clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

imgui_backend im_backend; 




public : 

	//Show_GUI m_show_gui = Show_GUI::NONE;

	void shutdown();

	//void display(E_ID window_id);

	void  im_set_backend_opengl(const GLFWwindow* window);

	private : 
	void clean_gui()
	{
	}

void cycle_active_gui_compnents();

	void prepar_im_newframe(GLFWwindow* Window);

};





#endif