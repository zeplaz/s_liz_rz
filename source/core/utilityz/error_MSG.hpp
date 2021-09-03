
//error_MSGZ
#ifndef SLIZERZ_01_ERROR_MSGZ_01_HPP
#define SLIZERZ_01_ERROR_MSGZ_01_HPP


typedef int ERRORCODE; 

	
	enum Error_Triage : int
	{ 
   
		LV1 =1,
		LV2 =2,
		LV0 =-1,
		RENDER_LZ=5,
		UNKNOWN_ERROR = 0,
		NON_ERROR = 255 
		
	};
 enum Exit_Error_Code : int{
   NO_ERROR = 0, 
   PARSER_FAIL = -11,
   TEXTURE_FAIL = -12,
   SHADER_FAIL = -13,
   MAIN_FAIL = -14,
   ENGINE_FAILURE = -15,
   OPENGL_FAILCAUGHT = -16,
   FILE_FORMATE_ERROR = -17,
   MAPLOOKUP_FAIL = -18,
   SHADER_LINK_FAIL = -19,
   STBI_LOAD_FAIL = -20,
   OI_UTILITYZ_FAIL =-21,
   IM_GUI_FAIL = -22,
   GWFLW_FAIL_CREATE = -23,
   GWFLW_FAIL_INIT = -24,
   GLEW_FAIL = -25
   };

#endif