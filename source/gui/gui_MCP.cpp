//render_GUI_MCP.cpp


#include "gui_MCP.hpp"

void gui_mgmt::cycle_active_gui_compnents()
	{
	            
	    for(auto it = gui_componets_list.begin(); it != gui_componets_list.end(); it++)
	        {

	       		if (it->remain_open == true)
	          	 	{}
	           	//	write_im_gui_compnentlist(it);
	          		
	        }
	    gui_componets_list.remove_if([](gui_compoent gc){ return !gc.remain_open;});
	           // gui_componets_list.remove_if()
	      //std::not1(std::mem_fun(&gui_compoent::is_remain_open)
	}	


void gui_mgmt::prepar_im_newframe(GLFWwindow* Window)
	{		
		ImGui_ImplOpenGL3_NewFrame();
	    im_backend.ImGui_ImplGlfw_NewFrame(Window);
	    ImGui::NewFrame();
	}


void gui_mgmt::display( GLFWwindow* window )
	{	
		//std::cout << "##->display...\n";
		prepar_im_newframe(window);
		cycle_active_gui_compnents();
		test_ispb.write();
	}

	void  gui_mgmt::im_set_backend_opengl(const GLFWwindow* window)
{
    im_backend.ImGui_ImplGlfw_Init_redux(window, true, GlfwClientApi_OpenGL);
        
    IM_ASSERT((int)strlen(im_backend.glsl_version) + 2 < IM_ARRAYSIZE(im_backend.g_GlslVersionString));
    strcpy(im_backend.g_GlslVersionString, im_backend.glsl_version);
    strcat(im_backend.g_GlslVersionString, "\n");
}



/*

void render_gui_mgmt::shutdown(){


		if (g_VboHandle) glDeleteBuffers(1, &g_VboHandle);
	    if (g_ElementsHandle) glDeleteBuffers(1, &g_ElementsHandle);
	    g_VboHandle = g_ElementsHandle = 0;

	    if (g_ShaderHandle && g_VertHandle) glDetachShader(g_ShaderHandle, g_VertHandle);
	    if (g_VertHandle) glDeleteShader(g_VertHandle);
	    g_VertHandle = 0;

	    if (g_ShaderHandle && g_FragHandle) glDetachShader(g_ShaderHandle, g_FragHandle);
	    if (g_FragHandle) glDeleteShader(g_FragHandle);
	    g_FragHandle = 0;

	    if (g_ShaderHandle) glDeleteProgram(g_ShaderHandle);
	    g_ShaderHandle = 0;


}



void render_gui_mgmt::shutdown()
	{
		
	    ///delite textures

	     if (gui_FontTexture)
	    {
	        ImGuiIO& io = ImGui::GetIO();
	        glDeleteTextures(1, &g_FontTexture);
	        io.Fonts->TexID = 0;
	        g_FontTexture = 0;
	    }

    }
    */