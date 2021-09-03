

#ifndef SLAZERZ_01_ENUMZ_ET_DEFAULTZ_001_HPP
#define SLAZERZ_01_ENUMZ_ET_DEFAULTZ_001_HPP



/*
*
*                 COLLECTION OF THE ENUMZ DEFULTS
*
*/


	//:::TEMPLATE FOR HEADER:::

/*
*
*                 |\ /|
*
*/

//--------------------------------------------------------------------------------------||


//*****************************************************************************************||

/*
*
*                 |\TICKER SYMBOL LIST/|
*
*/

#include <string>
typedef  std::string Symbol_Tag;
/*

 enum class Symbol_Tag : uint32_t
{

	INVALED,
  BTC_USDT,
	XLM_BTC,
  CHZ_USDT,
	ADA_BUSD,
	MATIC_BUSD,
	BNB_BUSD
};
*/
const std::basic_string<char> BTC_USDT("BTCUSDT");
const std::basic_string<char> XLM_BTC("XLMBTC");
const std::basic_string<char> CHZ_USDT("CHZUSDT");
const std::basic_string<char> ADA_BUSD("ADABUSD");
const std::basic_string<char> MATIC_BUSD("MATICBUSD");
const std::basic_string<char> BNB_BUSD("BNBBUSD");





//----------||
/*enum Period_Mili : long
{
  P1MIN   = 600,
  P3MIN   = 1800,
  P5MIN   = 3000,
  P10MIN  = 6000,
  P15MIN  = 9000,
  P30MIN  = 18000,
  P45MIN  = 27000,
  P1HOUR  = 36000,
  P2HOUR  = 72000,
  P4HOUR  = 144000,
  P8HOUR  = 288000,
  P10HOUR = 360000,
  P14HOUR = 504000,
  P24HOUR = 864000,
  P36HOUR = 1296000,
  P48HOUR = 1728000    
};*/

typedef long Period_Mili; 

const constexpr Period_Mili  P1MIN   = 600;
const constexpr Period_Mili  P3MIN   = 1800;
const constexpr Period_Mili  P5MIN   = 3000;
const constexpr Period_Mili  P10MIN  = 6000;
const constexpr Period_Mili  P15MIN  = 9000;
const constexpr Period_Mili  P30MIN  = 18000;
const constexpr Period_Mili  P45MIN  = 27000;
const constexpr Period_Mili  P1HOUR  = 36000;
const constexpr Period_Mili  P2HOUR  = 72000;
const constexpr Period_Mili  P4HOUR  = 144000;
const constexpr Period_Mili  P8HOUR  = 288000;
const constexpr Period_Mili  P10HOUR = 360000;
const constexpr Period_Mili  P14HOUR = 504000;
const constexpr Period_Mili  P24HOUR = 864000;
const constexpr Period_Mili  P36HOUR = 1296000;
const constexpr Period_Mili  P48HOUR = 1728000;    


//*****************************************************************************************||

/*
*
*                 |\price_point_cmder /|
*
*/

constexpr long MAX_PLT_ARRAY = 300000;


//*****************************************************************************************||
/*
*
*			|\RENDER/| 
*
*/

//constexpr const int DEFAULT_WIDTH = 1280;
//constexpr const int DEFAULT_HIGHT = 720;






#endif