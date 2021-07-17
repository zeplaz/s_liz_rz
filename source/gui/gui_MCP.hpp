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

#include "windowBuilder.hpp"

#include "../core/utilityz/enumz_et_defultz.hpp"

#include "../core/opengl_utility.hpp"




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

input_symbol_price_box test_ispb; 


public : 

	Show_GUI m_show_gui = Show_GUI::NONE;

	void shutdown();

	void add_compoent();

	void display( GLFWwindow* window );

	private : 
	void clean_gui()
	{
	}

void cycle_active_gui_compnents();

	void prepar_im_newframe(GLFWwindow* Window);

};



	/*void write_im_gui_compnentlist(std::forward_list<price_alert_comp>::iterator it)
	{	

		std::cout << "##->write_im_gui_compnentlist...\n";

	
	}

	void write_price_alert_group(std::forward_list<price_alert_comp>::iterator it)
	{	
		ImGui::Begin("price_alerts")
		ImGui::BeginGroup(); 
		
		
		 ImGui::EndGroup();
		 ImGui::End();
	}
	////
	// TEST FUNCIONS/
	/////
	//std::forward_list<gui_compoent> gui_componets_list; 

/*void add_gui_compent_test()
{	
		gui_compoent ts1_gui_1;
		ts1_gui_1.im_win_parmz.title= "new test window";
		ts1_gui_1.im_win_parmz.set_window_flags(ts1_gui_1.im_win_flag);

		gui_componets_list.push_front(ts1_gui_1);


	//gui_componets_list.emplace_front();
}*/

//----------------------------------------------
*/



#endif