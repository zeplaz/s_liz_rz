//engine.cpp

#include "engine.hpp"


void engine::ignition()
{ 
  m_engine_status = Engine_State::IGNITION;
 
  render_mgmt.setup_contex();
  m_sym_online|= Systems_Online::RENDERER; 
  render_mgmt.set_gui_api();
  m_sym_online|= Systems_Online::IM_GUI; 
  binc_mgmt.startup();
  m_sym_online|= Systems_Online::BINACE_API;  

}
//int run();
void engine::shutdown()
{
  render_mgmt.shutdown();
  m_sym_online ~= Systems_Online::RENDERER; 
  m_sym_online ~= Systems_Online::IM_GUI; 

  binc_mgmt.shutdown();
  m_sym_online ~= Systems_Online::BINACE_API;  
}


//void configure(int argc, char* argv[]);
Engine_State engine::cycle()
{
  m_engine_status = Engine_State::RUNNING;
  bool shutdown_signa = false;
  bool halt_signal = false; 
  bool window_status = true;   

  while (window_status|| !shutdown_signa)
  {     
        
    //task_cmder.do();



        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        glfwPollEvents();

        // Start the Dear ImGui frame
    
  render_mgmt.display();

 	double price = binc_mgmt.get_price("BTCBUSD");

	std::string wholeting = std::to_string(binc_mgmt.get_price("BTCBUSD"));

	std::cout << "\n*******\n  #->BTCBUSD::" << price  <<"\n***********\n" << wholeting << "\n\n";

 if(!glfwWindowShouldClose(window))
 {
  window_status = false; 
  m_engine_status = Engine_State::SHUTDOWN; 
 }

}

return m_engine_status;
}
