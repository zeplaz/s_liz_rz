//

#ifndef SLIZERZ_01_BASE_WINDOW_01_HPP
#define SLIZERZ_01_BASE_WINDOW_01_HPP

//base_window.hpp

#include <string>
#include "../utilityz/errorhandler.hpp"

enum class WINDOW_FRAMWORK
{
SDL,
GLFW
};

namespace SL_ZER
{
	inline static WINDOW_FRAMWORK win_framework; 

	inline static void set_win_framework(WINDOW_FRAMWORK const& win)
	{
		win_framework = win; 
	}
}

	constexpr int DEFAULT_MAIN_VEWPORT_WIDTH  = 700;
	constexpr int DEFAULT_MAIN_VEWPORT_HIGHT  = 700;
	
	constexpr int CLEAR_COLOURS_INT[] = {27,52,16,255};

//struct abstract_window_implmentor; 
class base_window
{
	public : 
	
	friend struct abstract_window_implmentor; 
	
    bool shutdown_signa = false; 
    inline static bool Resized = false; 
    
    int frameportbuffer_width;  
    int frameportbuffer_height;
    //base_window(abstract_window_implmentor* imp) : implemntor(imp)
    
	virtual ERRORCODE init() =0; 
	virtual ERRORCODE setup_context() = 0; 
	virtual ERRORCODE create_window(int width, int hight, std::string title) = 0;
	virtual void shutdown() = 0; 

	virtual void* window_hanlde() = 0; 
	virtual void if_resized() =0 ; 

	virtual ~base_window() {};

 

	protected : 
	//base_window() = delete; 
	const char* glsl_version = "#version 460";

};


struct abstract_window_implmentor
{	friend class base_window; 

	base_window* window; 
	virtual void poll_events() = 0;
	virtual void render() =0;
	virtual long double get_window_time_seconds() =0; 
	virtual ~abstract_window_implmentor() {}
}; 



#endif
