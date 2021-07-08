//ut_renderer_0.1.cpp

/*
g++ -std=c++20 -pg -fconcepts-ts -I../../3rd_party/imgui/backends -I../../3rd_party -I../../3rd_party/imgui  \
ut_renderer_0_1.cpp ../core/render.cpp ../core/opengl_utility.cpp  ../gui/gui_MCP.cpp \
../../3rd_party/imgui/imgui.cpp ../../3rd_party/imgui/imgui_draw.cpp ../../3rd_party/imgui/imgui_tables.cpp ../../3rd_party/imgui/imgui_widgets.cpp \
../../3rd_party/imgui/backends/imgui_impl_opengl3.cpp \
 -lcurl -lcrypto -lwebsockets -lbinacpp -ljsoncpp -lpthread -lGLEW -lglfw -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl 
 */



#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wpragmas"                  // warning: unknown option after '#pragma GCC diagnostic' kind
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"      // warning: cast to pointer from integer of different size
#pragma GCC diagnostic ignored "-Wformat-security"          // warning: format string is not a string literal (potentially insecure)
#pragma GCC diagnostic ignored "-Wdouble-promotion"         // warning: implicit conversion from 'float' to 'double' when passing argument to function
#pragma GCC diagnostic ignored "-Wconversion"               // warning: conversion to 'xxxx' from 'xxxx' may alter its value
#pragma GCC diagnostic ignored "-Wmisleading-indentation"   // [__GNUC__ >= 6] warning: this 'if' clause does not guard this statement      // GCC 6.0+ only. See #883 on GitHub.
#endif


#include "../core/render.hpp"
#include "../gui/gui_MCP.hpp"  
#include "imgui_impl_opengl3.h"

int main(int argc, char** argv)
{

render mrender;

mrender.setup_contex();

gui_mgmt mgui; 
mgui.setup_imgui(mrender.window);



glm::vec4 clear_colouer { 0.3,0.3,0.4, 0.4};
bool show_another_window = true;
 while (!glfwWindowShouldClose(mrender.window))
    {


    	 glfwPollEvents();

    	         ImGui_ImplOpenGL3_NewFrame();
        mgui.ImGui_ImplGlfw_NewFrame(mrender.window);
        ImGui::NewFrame();
    	  if (show_another_window)
        {
            ImGui::Begin("Another Window", &show_another_window);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
            ImGui::Text("Hello from another window!");
            if (ImGui::Button("Close Me"))
                show_another_window = false;
            ImGui::End();
        }

         ImGui::Render();


         int display_w, display_h;
        glfwGetFramebufferSize(mrender.window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
    	  glClearColor(0.2f, 0.2f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        /////DRAW

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());



        ///swap


        glfwSwapBuffers(mrender.window);

        ///
    }


return 0;

}


