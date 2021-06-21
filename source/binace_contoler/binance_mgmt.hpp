#ifndef SLAZERZ_01_BINANCE_MGMT_001_HPP
#define SLAZERZ_01_BINANCE_MGMT_001_HPP


#define KGRN "\033[0;32;32m"
#define KCYN "\033[0;36m"
#define KRED "\033[0;32;31m"
#define KYEL "\033[1;33m"
#define KBLU "\033[0;32;34m"
#define KCYN_L "\033[1;36m"
#define KBRN "\033[0;33m"
#define RESET "\033[0m"


//#include "enumz_et_defultz.hpp"


//std::libs
#include <string>
#include <vector>

//3rd party libz
#include <json/json.h>
//--------------------------------------------------------------------------||


// FORWARD DELCRATIONS
struct price_point_dtp; 
struct price_point_dl;
struct allprices;
 
template <typename>
struct streamed_channel;






//--------------------------------------------------------------------------||
/*
*
*                 |\BINANCE_MGMT/|
*
*/


class binance_mgmt
{	
	
	public : 
	void startup(std::string & a_key, std::string & s_key);
	long server_time();
	double get_price_d(std::string const& symblol);

	price_point_dtp get_pp_dtp(std::string const& symblol);
	price_point_dl get_pp_dl(std::string const& symbol);

	Json::Value get_klinez(std::string const& symbol, std::string inval, long st, long et, int limit);

	void update_all_prices(allprices& allp);
	
	//price_point_s raw_price_time_data(std::string const& symbol);

	
	//template <typename T>
	//T begin_streaming_channel( std::string const& in_channel);


};

#endif
