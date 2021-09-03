//engine.cpp

#include "engine.hpp"

#include "../analytic/analytic_MCP.hpp"
#include "render.hpp"

#include "utilityz/locks.hpp"
///

///
#include <iostream>

void engine::load_testz_systems()
{
 
 
std::cout << "\n####-> load_testz_systems() \n\n update_prices movethough\n";
an_proc.mprice_cmder.create_price_floor(MATIC_BUSD,1.210);
an_proc.mprice_cmder.create_price_floor(MATIC_BUSD,1.230);
an_proc.mprice_cmder.create_price_floor(MATIC_BUSD,1.2210);

an_proc.mprice_cmder.create_price_roof(MATIC_BUSD,1.1);
an_proc.mprice_cmder.create_price_roof(MATIC_BUSD,1.3270);
an_proc.mprice_cmder.create_price_roof(MATIC_BUSD,1.22);

create_new_window();

//mgui.add_gui_compent_test();

}


engine::egnine()
  {
   mrender      = new render(this);
   analytic_MCP = new analytic_MCP;  
  }

void engine::shutdown()
{
  std::cout <<"attemping shutdown... load atomic false\n";
  an_proc.back_binace_oper.keep_binance_runing.store(false);


  window_status = false; 
  ImGui_ImplOpenGL3_Shutdown(); 
  ImGui::DestroyContext();

  glfwDestroyWindow(mrender.window);
  glfwTerminate();
  m_engine_status = Engine_Status::SHUTDOWN; 
}

ERRORCODE engine::ignition()
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



void engine::gui_render_draw()
{

  ///rendering and gui stuff
       glfwPollEvents();


       mgui.display(mrender.window);


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

Engine_Status engine::cycle()
{
  m_engine_status = Engine_Status::RUNNING;    
  int i = 0;
  std::cout <<"\n---| engine::cycle()||\n";
  
  while (!)
   

    {
      i++;
      
        //analyc stiff
      if(0==i%50) 
      {
        std::cout <<"MAINTHREAD##-->testing alert sycle\n";
         an_proc.cycle_prices_alerts_redux();
      }

      gui_render_draw();

    }
      
      
      shutdown();
   
      if (binance_background_thread->joinable())
      {
        std::cout <<"joinable..n";
         binance_background_thread->join();
      }

  return m_engine_status;
}

