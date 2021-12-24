

//defualts.Namespace



namespace SL_ZER
{	
	enum class WINDOW_FRAMWORK
{
SDL,
GLFW
};

	inline static WINDOW_FRAMWORK win_framework; 
	inline static bool RUNTIME_FRAMWORK_SET = false; 

	inline static void set_win_framework(WINDOW_FRAMWORK const& win)
	{
		win_framework = win; 
		RUNTIME_FRAMWORK_SET = true;
	}

	constexpr int DEFAULT_MAIN_VEWPORT_WIDTH  = 700;
	constexpr int DEFAULT_MAIN_VEWPORT_HIGHT  = 700;
	const std::string MAIN_WINDOW_TITLE = "SL_ZER Analytics Main"; 
	constexpr int CLEAR_COLOURS_INT[] = {27,52,16,255};
	static inline const char* glsl_version = "#version 460";
	
}