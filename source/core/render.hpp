///render


#ifndef SLAZERZ_01_RENDER_MCP_001_HPP
#define SLAZERZ_01_RENDER_MCP_001_HPP

#include "opengl_utility.hpp"


struct render
{
	render_gui_mgmt	gui_mgmt;
	//shader_program_mgmt shader_mgmt;
	GLFWwindow*     window;

	int setup_contex();

	inline void set_gui_api();

	void frame_write();

	bool display();

	void shutdown();
	

};

////////////////////////////////////////////////////

#include "imgui.h"

//#include "imgui_impl_glfw.h"
//#include "imgui_impl_opengl3.h"

enum  class Show_GUI : uint32_t {
	
	NONE             =0x00,
	SHOW_MAIN_MENU   =0x01,
	SHOW_FULL_SCREEN =0x02


};

static void HelpMarker(const char* desc)
{
    ImGui::TextDisabled("(?)");
    if (ImGui::IsItemHovered())
    {
        ImGui::BeginTooltip();
        ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
        ImGui::TextUnformatted(desc);
        ImGui::PopTextWrapPos();
        ImGui::EndTooltip();
    }
}



struct gui_componet
{
	int id;
	std::string name;


}

class gui_mgmt
{	
private: 
	

	ImVec4 gui_clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
public : 

	Show_GUI m_show_gui = Show_GUI::NONE;

	int setup_contex();

	void setup_imgui();
	
	void shutdown_opengl();

	void add_compoent();

	void display();
	

};

#endif