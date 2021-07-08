//engine.cpp

#include "engine.hpp"
#include "../analytic/analytic_MCP.hpp"
#include "utilityz/locks.hpp"

#include <iostream>

void engine::load_testz_systems()
{
 
 
std::cout << "update_prices movethough";
/*

an_proc.mprice_cmder.create_price_alert(MATIC_BUSD,1.2200,false);
an_proc.mprice_cmder.create_price_alert(MATIC_BUSD,1.2370,true);
an_proc.mprice_cmder.create_price_alert(MATIC_BUSD,1.1200,false);
an_proc.mprice_cmder.create_price_alert(MATIC_BUSD,1.250,true);
an_proc.mprice_cmder.create_price_alert(MATIC_BUSD,1.3100,false);
an_proc.mprice_cmder.create_price_alert(MATIC_BUSD,1.2270,true);
*/





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
//int run();
/*
void engine::shutdown()
{
  //render_mgmt.shutdown();
 //m_sym_online ~= Systems_Online::RENDERER; 
  //m_sym_online ~= Systems_Online::IM_GUI; 

 // binc_mgmt.shutdown();
//  m_sym_online ~= Systems_Online::BINACE_API;  
}


//void configure(int argc, char* argv[]);
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


  while (window_status|| !shutdown_signa)
 {     
        
    //task_cmder.do();



        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
      //  glfwPollEvents();

        // Start the Dear ImGui frame
    
  //render_mgmt.display();

 	//double price = binc_mgmt.get_price("BTCBUSD");

	//std::string wholeting = std::to_string(binc_mgmt.get_price("BTCBUSD"));

//	std::cout << "\n*******\n  #->BTCBUSD::" << price  <<"\n***********\n" << wholeting << "\n\n";

while(i<100)
{

std::cout << "\n-----------------------------cycle_prices_alerts_redux::" << '\n';
//auto start02 = chrono::high_resolution_clock::now();

 // an_proc.cycle_prices_alerts_redux();

//auto end02 = chrono::high_resolution_clock::now();
i++;

shutdown_signa = true;
m_engine_status = Engine_Status::SHUTDOWN; 
}
}

/*  chrono::duration<double> diff = end01-start01;
  
  std::cout << "time_dif1::cycle_prices_alerts::" << diff.count() << '\n';

  diff = end02-start02;
  std::cout << "time_dif2::cycle_prices_alerts_redux::" << diff.count() << '\n';*/

/*
 if(!glfwWindowShouldClose(window))
 {
  window_status = false; 
  m_engine_status = Engine_State::SHUTDOWN; 
 }

}

return m_engine_status;
}
*/