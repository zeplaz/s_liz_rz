//utilityz.cpp

#include "utilityz.hpp"
#include "enumz_et_defultz.hpp"
#include <iostream>

std::string Utility::Symbol_Tag_to_string(Symbol_Tag in_tag)
{

  if(in_tag ==Symbol_Tag::BTC_USDT)
  {
    return std::string("BTCUSDT");
  }

  else if(in_tag ==Symbol_Tag::XLM_BTC)
  {
    return std::string("XLMBTC");
  }

  else if(in_tag ==Symbol_Tag::CHZ_USDT)
  {
    return std::string("CHZUSDT");
  }

  else if(in_tag ==Symbol_Tag::ADA_BUSD)
  {
    return std::string("ADABUSD");
  }

  else if(in_tag ==Symbol_Tag::MATIC_BUSD)
  {
    return std::string("MATICBUSD");
  }

  else if(in_tag ==Symbol_Tag::BNB_BUSD)
  {
    return std::string("BNBBUSD");
  }

  /*
  else if(in_tag ==)
  {
    return std::string("");
  }
  */
  std::cerr <<"###ERRROR NOT VAILD Symbol_Tag\n";
  return "#NOTVAILD";
} 
/*


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
*/