
#ifndef SLAZERZ_01_ERROR_HANDLER_HPP
#define SLAZERZ_01_ERROR_HANDLER_HPP


/*#ifndef DEBUG_01
  BASE DEFINE FOR POSIOING EVEYTHING WITH DEBUGO LEVEL 1 YAH!
*/
#define DEBUG_01

#include "error_MSG.hpp"
#define FMT_HEADER_ONLY
//#include "fmt_includer.hpp"
//#include <fmt/core.h>
#include <fmt/format.h>
//#include <fmt/time.h>
#include <fmt/color.h>
//#include <fmt/printf.h>

#include <string>
 static std::string error_to_string(ERRORCODE in_error)
 {
   switch(in_error)
   { 
    case NO_ERROR : 
    return "NO_ERROR"; 
     case GLEW_FAIL :
     return "GLEW_FAIL";

     case GWFLW_FAIL_INIT :
     return "GWFLW_FAIL_INIT";

     case GWFLW_FAIL_CREATE :
     return "GWFLW_FAIL_CREATE";
     
     case IM_GUI_FAIL :
     return "IM_GUI_FAIL"; 
     
     case PARSER_FAIL :
     return "PARSER_FAIL";

     case TEXTURE_FAIL:
     return "TEXTURE_FAIL";

     case SHADER_FAIL :
     return "SHADER_FAIL";

     case MAIN_FAIL :
     return "MAIN_FAIL";

     case ENGINE_FAILURE:
     return "ENGINE_FAILURE";

     case OPENGL_FAILCAUGHT:
     return "OPENGL_FAILCAUGHT";

     case FILE_FORMATE_ERROR:
     return "FILE_FORMATE_ERROR" ;

     case MAPLOOKUP_FAIL:
     return "MAPLOOKUP_FAIL";

     case SHADER_LINK_FAIL:
     return "SHADER_LINK_FAIL";

     case STBI_LOAD_FAIL:
     return "STBI_LOAD_FAIL";

     case OI_UTILITYZ_FAIL:
     return "OI_UTILITYZ_FAIL";

     case YAHOO_CURL_PARSE_FAIL:
     return "YAHOO_CURL_PARSE_FAIL";

     default :
      std::string ue =  std::to_string(in_error);
      ue =  ue+"::UNKNOWN ERROR";
     return ue;
   }
 }


 struct Error_Rangler
 { 
  /*
  an Error Triage BELOW this value (LESS THEN)
  will trigger a fattel single and cause termination  
  */
  Error_Triage Alert_lvFattal = LV2;  

  fmt::rgb ERROR_COLOUR_LV0       = {231,20,40};
  fmt::rgb ERROR_COLOUR_LV1       = {175,175,20};
  fmt::rgb ERROR_COLOUR_LV2       = {120,100,18};
  fmt::rgb ERROR_COLOUR_RENDER_LZ = {120,70,200};
  fmt::rgb UNKNOWN_ERROR_COLOUR   = {10,220,192};
  fmt::rgb NO_ERROR_COLOUR        = {30,160, 30};


   void operator () (ERRORCODE inerror, Error_Triage et)
   {
     print_EC_ET( inerror,  et);
   }

   void set_Alert_level(Error_Triage al)
   {
    Alert_lvFattal = al; 
   }

 bool   is_fattel(ERRORCODE inerror, Error_Triage et) const
   {
      if(et == LV0)
      { return true;}

      if(et < Alert_lvFattal)
      {
        switch(inerror)
        {
          case ENGINE_FAILURE : 
          return true;
          
          case MAIN_FAIL : 
          return true;
        } 

        return false;        
   }
 }

    void print_EC_ET(ERRORCODE inerror, Error_Triage et) const
    { 
      
       auto  colour = [this](Error_Triage et)
          {
            switch(et)
            {
              case LV1 : 
              return ERROR_COLOUR_LV1;

              case LV2 :
              return ERROR_COLOUR_LV2;

              case LV0 :
              return ERROR_COLOUR_LV0;
              
              case RENDER_LZ : 
              return ERROR_COLOUR_RENDER_LZ;

              case UNKNOWN_ERROR : 
              return UNKNOWN_ERROR_COLOUR;

              default : 
              return NO_ERROR_COLOUR;
              
            }

          }; 
      
        fmt::print(fg(colour(et))| fmt::emphasis::bold,"ERRORCODE:{}\n",
                    error_to_string(inerror));

    }


    void print_EC_ET(ERRORCODE inerror, Error_Triage et, const char* notes) const
    { 
      
       auto  colour = [this](Error_Triage et)
          {
            switch(et)
            {
              case LV1 : 
              return ERROR_COLOUR_LV1;

              case LV2 :
              return ERROR_COLOUR_LV2;

              case LV0 :
              return ERROR_COLOUR_LV0;
              
              case RENDER_LZ : 
              return ERROR_COLOUR_RENDER_LZ;

              case UNKNOWN_ERROR : 
              return UNKNOWN_ERROR_COLOUR;

              default : 
              return NO_ERROR_COLOUR;
              
            }

          }; 
      
        fmt::print(fg(colour(et))| fmt::emphasis::bold,"ERRORCODE:{}::##-> {} \n",
                    error_to_string(inerror),notes);
        
    }
    void print_ERROR_time()
    {
    
      
    }


 };


namespace Utility
{


static void Print_Error(ERRORCODE inerror, Error_Triage et) 
{
  Error_Rangler er; 

  er.print_EC_ET(inerror, et);
}

}

#endif

