//engine.hpp

#ifndef SLIZERZ_01_ENGINE_01_HPP
#define SLIZERZ_01_ENGINE_01_HPP

 //---these are more likly to be offical modualiset, vs the other as full systems..
/**MODUALS* CONVERT TO PROPER MODUALS OR VISEVRA*/ 


//CORE//
//#include "render.hpp"

//utilityz//
#include "utilityz/flag_templatez.hpp"
//#include "utilityz/errorhandler.hpp"
//#include "utilityz/id_utilityz.hpp"

//SLH//
#include <thread>


//Subsystems//
//#include "../analytic/analytic_MCP.hpp"
//#include "../gui/gui_MCP.hpp"


//*****************************************************************************************||
/*
*
*     |\ENGINE/| 
*
*/

inline static int keep_run = true; 

enum class Engine_Status : unsigned char
{
  INITAL,
  CONFIGURED,
  IGNITION,
  READY,
  RUNNING,
  SHUTDOWN,
  STALL,
  FAILURE
};

enum class Systems_Online : uint32_t
{ 
  SYM_NULL  =0x00, 
  RENDERER  =0x01,
  IM_GUI    =0x02,
  SYM_INPUTS=0x04,
  BINACE_API=0x08
};

template<>
  struct EnableBitMaskOperators<Systems_Online>
    {
       static const bool enable = true;
    };

//*********************************************************************//

//Forward declrations//

class analytic_MCP;
struct render;

///    

struct engine 
{

  inline static int alive_objects ={0}; 

  egnine();

  //enum systems montor
  Engine_Status  m_engine_status = Engine_Status::INITAL;
  Systems_Online m_sym_online    = Systems_Online::SYM_NULL;
 
  //modualer systems
  analytic_MCP*    an_proc;
  render*          mrender; 
  
  //thread stuff...
  std::thread* binance_background_thread; 


  /////////
  void load_testz_systems();

  ERRORCODE ignition();
  void shutdown();

  Engine_Status cycle();

private: 
  void kickoff_background_binance_thread();
 // void gui_render_draw();

//switches 

 inline static bool shutdown_signa = false;
 inline static bool halt_signal    = false; 
 inline static bool window_status  = true;   

  ///handle a
  bool stop = false;
  char loop_n; 

  
//DEBUG
  bool show_another_window = true;
 
};


#endif