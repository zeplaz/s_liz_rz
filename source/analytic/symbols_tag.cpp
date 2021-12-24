

Symbol_Tag Analytic::string_to_symbol(std::string symbol)
{
  if(symbol=="BTCUSDT")
  {
    return Symbol_Tag::BTC_USDT;
  }

  else if(symbol=="XLMBTC")
  {
     return Symbol_Tag::XLM_BTC;
  }
else if(symbol=="ADABUSD")
  {
     return Symbol_Tag::ADA_BUSD;
  }
  else if(symbol=="BNB_BUSD")
  {
     return Symbol_Tag::BNB_BUSD;
  }
  else if(symbol=="CHZUSDT")
  {
     return Symbol_Tag::CHZ_USDT;
  }
  else if(symbol=="MATICBUSD")
  { 
      #ifdef DEBUG_01
      std::cout << "\nDEBUG@***MATIC_BUSD FOUND::\n";
      #endif
     return Symbol_Tag::MATIC_BUSD;
  }

  else if(symbol=="")
  {
     return Symbol_Tag: ;
  }
  

  // std::cerr <<"###ERRROR NOT VAILD Symbol_Tag\n";
  return Symbol_Tag::INVALED;

}


std::string Analytic::Symbol_Tag_to_string(Symbol_Tag in_tag)
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
  
  std::cerr <<"###ERRROR NOT VAILD Symbol_Tag\n";
  return "#NOTVAILD";
} 