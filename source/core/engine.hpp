//engine.hpp


#ifndef SLIZERZ_01_ENGINE_01_HPP
#define SLIZERZ_01_ENGINE_01_HPP


//#include "analytic/analytic_processor_MCP.hpp"
//#include "core/render.hpp"
#include "core/utilityz/enumz_et_defultz.hpp"

//forward declrations
class analytic_processor;
struct render;

//*********************************************************************//

struct engine 
{
  Engine_State   m_engine_status = Engine_State::INITAL;
  Systems_Online m_sym_online    = Systems_Online::SYM_NULL;
	

  //sceduiler for batched tasks
 // task_cmder tasker;


// modualer systems?
  analytic_processor a_proc_mgmt;
  render render_mgmt;
  
   // binance_mgmt binac_mgmt;  


  void ignition();
  void shutdown();
  void ignition();
  Engine_State cycle();

};

#endif