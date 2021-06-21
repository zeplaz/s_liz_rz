//binace_mgmt.cpp		

#include "binance_mgmt.hpp"

#include "../core/utilityz/utilityz.hpp"
#include "../core/utilityz/timez.hpp"
#include "../core/compoent_stucts.hpp"



//3rdpartylibs
#include "../../3rd_party/binacpp/lib/libbinacpp/include/binacpp.h"
#include "../../3rd_party/binacpp/lib/libbinacpp/include/binacpp_websocket.h"


//STD:lbiz
#include <iostream>
#include <algorithm>
#include <locale> 




 void binance_mgmt::update_all_prices(allprices& allp)
{
	Json::Value alltickers;
	BinaCPP::get_allPrices( alltickers );
	
	allp.price_by_smyb.clear();
	allp.price_by_smyb.last_update = this->server_time();

	for ( int i = 0 ; i < alltickers.size() ; i++ )
	{
		allp.price_by_smyb.insert(std::make_pair(alltickers[i]["symbol"].asString(),std::stod(alltickers[i]["price"].asString()))) ;		
	}

}

Json::Value binance_mgmt::get_klinez(std::string const& symbol, std::string inval, long st, long et, int limit)
	{
		Json::Value result; 
		BinaCPP::get_klines( symbol.c_str(),inval.c_str() , st, et, limit, result);

		return result;	
	}



price_point_dl binance_mgmt::get_pp_dl(std::string const& symbol)
{
	Json::Value alltickers;
		double ret;
		long tp;
		std::string str_symbol(symbol);

		price_point_dl pps; 
		//std::transform(symbol.begin(), symbol.end(), str_symbol.begin(), std::toupper);
		
		BinaCPP::get_allPrices( alltickers );
		//tp = chrono::steady_clock::now();

		for ( int i = 0 ; i < alltickers.size() ; i++ ) {
			if ( alltickers[i]["symbol"].asString() == str_symbol ) {
				
				tp = this->server_time();
				ret = std::stod(alltickers[i]["price"].asString());
				break;
			}
			
		}	

	 pps.price = ret;
	 pps.time_point = tp;

	 return pps;
}

void binance_mgmt::startup(std::string & a_key, std::string & s_key)
	{

	BinaCPP::init( a_key , s_key );
	Json::Value result;

	BinaCPP::get_serverTime( result ) ;

	std::cout << "#-> Binance startup severtime is" << result << '\n'; 
	}
	//void login();

long  binance_mgmt::server_time()
{
	Json::Value result;
	BinaCPP::get_serverTime( result );
	return result["serverTime"].asLargestInt();

}
double binance_mgmt::get_price_d(std::string const& symblol)
	{	

	return BinaCPP::get_price(symblol.c_str());

	}

	price_point_dtp binance_mgmt::get_pp_dtp(std::string const& symbol)
	{

		Json::Value alltickers;
		double ret;
		clock_time_point tp;
		std::string str_symbol(symbol);

		price_point_dtp pps; 
		//std::transform(symbol.begin(), symbol.end(), str_symbol.begin(), std::toupper);
		
		BinaCPP::get_allPrices( alltickers );
		tp = chrono::steady_clock::now();

		for ( int i = 0 ; i < alltickers.size() ; i++ ) {
			if ( alltickers[i]["symbol"].asString() == str_symbol ) {
				

				ret = std::stod(alltickers[i]["price"].asString());
				break;
			}
			
		}	


	 pps.price = ret;
	 pps.time_point = tp;

	 return pps;
	}




