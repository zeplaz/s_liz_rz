//engine.hpp


#ifndef SLIZERZ_01_ENGINE_01_HPP
#define SLIZERZ_01_ENGINE_01_HPP

#include "../analytic/analytic_MCP.hpp"
#include "render.hpp"
#include "../gui/gui_MCP.hpp"
#include "utilityz/enumz_et_defultz.hpp"


#include <thread>

//forward declrations
//class  analytic_MCP;


inline static int keep_run = true; 


//*********************************************************************//

struct engine 
{
//enum systems montor
  Engine_Status   m_engine_status = Engine_Status::INITAL;
  Systems_Online m_sym_online    = Systems_Online::SYM_NULL;

    // modualer systems
  analytic_MCP an_proc;
  render mrender; 
  gui_mgmt mgui; 

//thread stuff...
  std::thread* binance_background_thread; 

void ignition();
void load_testz_systems();

private: 
  void kickoff_background_binance_thread();

  

};

#endif