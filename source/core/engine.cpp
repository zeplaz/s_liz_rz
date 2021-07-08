//engine.cpp

#include "engine.hpp"
#include "../analytic/analytic_MCP.hpp"
#include "utilityz/locks.hpp"
///
#include "imgui_impl_opengl3.h"
///
#include <iostream>

void engine::load_testz_systems()
{
 
 
std::cout << "update_prices movethough";
an_proc.mprice_cmder.create_price_floor(MATIC_BUSD,1.210);
an_proc.mprice_cmder.create_price_floor(MATIC_BUSD,1.230);
an_proc.mprice_cmder.create_price_floor(MATIC_BUSD,1.2210);

an_proc.mprice_cmder.create_price_roof(MATIC_BUSD,1.1);
an_proc.mprice_cmder.create_price_roof(MATIC_BUSD,1.3270);
an_proc.mprice_cmder.create_price_roof(MATIC_BUSD,1.22);

}



void engine::shutdown()
{
  std::cout <<"attemping shutdown... load atomic false\n";
  an_proc.back_binace_oper.keep_binance_runing.store(false);
}

void engine::ignition()
{ 
  m_engine_status = Engine_Status::IGNITION;
 

  mrender.setup_contex();
  m_sym_online|= Systems_Online::RENDERER; 

  mgui.setup_imgui(mrender.window);
  m_sym_online|= Systems_Online::IM_GUI; 
  
  this->kickoff_background_binance_thread();  

}

void engine::kickoff_background_binance_thread()
{
  binance_background_thread = new std::thread(an_proc.back_binace_oper);
  m_sym_online|= Systems_Online::BINACE_API;  
}

Engine_Status engine::cycle()
{
  m_engine_status = Engine_Status::RUNNING;
  bool shutdown_signa = false;
  bool halt_signal = false; 
  bool window_status = true;   


  ///handle a
  bool stop = false;
  char loop_n; 
  int i = 0;

 bool show_another_window = true;

      

while (!glfwWindowShouldClose(mrender.window))
    {
i++;
//analyc stiff
  if(0==i%50) 
{
  std::cout <<"MAINTHREAD##-->testing alert sycle\n";
  an_proc.cycle_prices_alerts_redux();
}


///rendering and gui stuff
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
  shutdown();
  window_status = false; 
  m_engine_status = Engine_Status::SHUTDOWN; 
         


    if (binance_background_thread->joinable())
    {
      std::cout <<"joinable..n";
       binance_background_thread->join();
    }

return m_engine_status;
}


//int run();
/*
void engine::shutdown()
{
  //render_mgmt.shutdown();
  shutdown_signa = true;
m_engine_status = Engine_Status::SHUTDOWN; 
}
 //m_sym_online ~= Systems_Online::RENDERER; 
  //m_sym_online ~= Systems_Online::IM_GUI; 

 // binc_mgmt.shutdown();
//  m_sym_online ~= Systems_Online::BINACE_API;  
}


//void configure(int argc, char* argv[]);
*/