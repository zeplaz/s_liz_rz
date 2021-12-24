//utilityz.cpp

#include "utilityz.hpp"
#include <iostream>



std::string Utility::which_systems(Systems_Online sym_comp)
{
  std::string  sym = "#->***Current Running systems***\n\n";
  
   if((sym_comp & Systems_Online::SYM_NULL) !=0)
  {
    return sym += "||NONE||";
  }

  if(sym_comp & Systems_Online::RENDERER !=0)
  {
    sym +="|RENDERER|\n";
  }

    if(sym_comp & Systems_Online::IM_GUI !=0)
  {
    sym +="|IM_GUI|\n";
  }

    if(sym_comp & Systems_Online::SYM_INPUTS !=0)
  {
    sym +="|SYM_INPUTS|\n";
  }

    if(sym_comp & Systems_Online::BINACE_API !=0)
  {
    sym +="|BINACE_API|\n";
  }

  return sym; 
}
