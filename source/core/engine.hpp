//engine.hpp

#ifndef SLIZERZ_01_ENGINE_01_HPP
#define SLIZERZ_01_ENGINE_01_HPP



 //---these are more likly to be offical modualiset, vs the other as full systems..
/**MODUALS* CONVERT TO PROPER MODUALS OR VISEVRA*/


//CORE//
//#include "render.hpp"

//utilityz//
#include "utilityz/flag_templatez.hpp"
#include "utilityz/errorhandler.hpp"

#include "utilityz/id_utilityz.hpp"

//SLH//
#include <thread>

#include "render/render.hpp"


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

#define DEFAULT_WIN_HIGHT  1000
#define DEFAULT_WIN_WIDTH  1000

constexpr unsigned int ANALYTIC_DUTY_CYCLE = 50;     
const std::string MAIN_WIN_TITLE = "Main_Window_s_liz_rz";

//Forward declrations//

class analytic_MCP;
class render_MCP;
///

struct engine
{

  inline static float delta_time = {0.0f};        // time between current frame and last frame
  inline static float lastFrame = {0.0f};

  inline static int alive_objects ={0};
  inline static unsigned long long int cycle_count ={0};

  //enum systems montor
  Engine_Status  m_engine_status = Engine_Status::INITAL;
  Systems_Online m_sym_online    = Systems_Online::SYM_NULL;

  //modualer systems
 //analytic_MCP*    an_proc;
  render_MCP*          mrender = nullptr;


  //thread stuff...
  std::thread* binance_background_thread = nullptr;
  std::thread* yahoo_background_thread = nullptr;


  /////////
  engine();
  void load_testz_systems();
  ERRORCODE ignition();

  void config_render_window(char* flag);
  
  void shutdown();
  Engine_Status cycle();
  void cycles_anlytics();
  ERRORCODE launch_main_window();



private:
  void kickoff_background_binance_thread();
  void kickoff_background_yahoo_thread();

  //void cycle_for_sdl();
  //void cycle_for_glfw(); 

  //void gui_render_draw();
  void join_active_threads(); 
//switches

 inline static bool shutdown_signa = false;
 inline static bool halt_signal    = false;
 inline static bool window_status  = true;


//DEBUG
  bool show_another_window = false;

};


#endif
