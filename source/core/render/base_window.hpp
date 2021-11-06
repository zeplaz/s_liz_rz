//

#ifndef SLIZERZ_01_BASE_WINDOW_01_HPP
#define SLIZERZ_01_BASE_WINDOW_01_HPP

//base_window.hpp


#include <string>

enum class WINDOW_FRAMWORK
{
SDL,
GLFW
};


class base_window
{
	public : 
	constexpr int DEFAULT_MAIN_VEWPORT_WIDTH  = 700;
	constexpr int DEFAULT_MAIN_VEWPORT_HIGHT  = 700;
	
	constexpr int CLEAR_COLOURS_INT[] = {27,52,16,255};
	const glm::vec4 CLEAR_COLOUR_GLM  {0.45f, 0.55f, 0.60f, 1.00f}; 

	
	ERRORCODE init() =0; 
	ERRORCODE create_window(int width, int hight, std::string title) = 0;
	ERRORCODE setup_context() = 0; 
	ERRORCODE shutdown() = 0; 

	void render() = 0; 

	ERRORCODE glew_check() =0; 

	~base_window() = 0; 

	protected : 
	
};


#endif

/*
//
std::vector<std::function<void()>> commands;


for(auto& command:commands)command();

struct draw{};
using draw_signature = void(draw,window);
/