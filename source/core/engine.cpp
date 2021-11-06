//engine.cpp

#include "engine.hpp"

//#include "../analytic/binace_analytic_MCP.hpp"
//#include "render.hpp"


#include "utilityz/locks.hpp"
#include "glfw_windowBuilder.hpp"



void engine::load_testz_systems()
{

//mgui.add_gui_compent_test();

/*std::cout << "\n####-> load_testz_systems() \n\n update_prices movethough\n";
an_proc.mprice_cmder.create_price_floor(MATIC_BUSD,1.210);
an_proc.mprice_cmder.create_price_floor(MATIC_BUSD,1.230);
an_proc.mprice_cmder.create_price_floor(MATIC_BUSD,1.2210);

an_proc.mprice_cmder.create_price_roof(MATIC_BUSD,1.1);
an_proc.mprice_cmder.create_price_roof(MATIC_BUSD,1.3270);
an_proc.mprice_cmder.create_price_roof(MATIC_BUSD,1.22);*/



}


engine::engine()
  {
     mrender      = new render_MCP(this);
    // analytic_MCP = new analytic_MCP;


  }

void engine::shutdown()
{
  fmt::print("\nattemping shutdown... load atomic false\n");
  //an_proc.back_binace_oper.keep_binance_runing.store(false);

  window_status = false;
  //ImGui_ImplOpenGL3_Shutdown();
  //ImGui::DestroyContext();

  //glfwDestroyWindow(mrender.window);
  glfwTerminate();
  m_engine_status = Engine_Status::SHUTDOWN;
}



ERRORCODE engine::ignition()
{
  m_engine_status = Engine_Status::IGNITION;



    ERRORCODE co = this->launch_main_window();
    if(co != NO_ERROR)
    {
      m_engine_status = Engine_Status::FAILURE;
      return co;
    }


  m_sym_online|= Systems_Online::RENDERER;


  //mgui.setup_imgui(mrender.window);
  m_sym_online|= Systems_Online::IM_GUI;

  //this->kickoff_background_binance_thread();
  return NO_ERROR;

}

void engine::kickoff_background_binance_thread()
{
  //binance_background_thread = new std::thread(an_proc.back_binace_oper);
  m_sym_online|= Systems_Online::BINACE_API;
}



void engine::gui_render_draw()
{

  ///rendering and gui stuff


       //glfwPollEvents();


     //  mgui.display(mrender.window);
/*

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
        */

}


void engine::cycles_anlytics()
{
       if(0==cycle_count%50)
      {
        //std::cout <<"MAINTHREAD##-->testing alert sycle\n";
         //an_proc.cycle_prices_alerts_redux();
      }

}

void engine::cycle_for_sdl()
{


}

void engine::cycle_for_glfw()
{

  while (!shutdown_signa)
   {
      cycle_count++;
      float current_frame = glfwGetime();
      shutdown_signa = win_glfw->poll_to_close();

   }
}

void engine::join_active_threads()
{
  if(binance_background_thread !=nullptr)
    {
    if (binance_background_thread->joinable())
      {
         fmt::print("##->joinable..binance_background_threadn\n");
         binance_background_thread->join();
      }
    }
  if(yahoo_background_thread !=nullptr)
    {
    if (yahoo_background_thread->joinable())
      {
        mt::print("##->joinable..yahoo_background_thread\n");
        yahoo_background_thread->join();
      }
    }


        /**/
}
Engine_Status engine::cycle()
{
  m_engine_status = Engine_Status::RUNNING;
  fmt::print("\n---| engine::cycle()||\n");


    if(mrender->win_framework==WINDOW_FRAMWORK::SDL)
    {
      this->cycle_for_sdl();
    }

    if(mrender->win_framework == WINDOW_FRAMWORK::GLFW)
     {
      this->cycle_for_glfw();
     } 

      shutdown();



  return m_engine_status;
}
