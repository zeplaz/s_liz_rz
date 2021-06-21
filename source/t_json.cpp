///testjson

//g++ -fconcepts-ts -I../3rd_party/binacpp/lib/libbinacpp/include t_json.cpp binace_contoler/binance_mgmt.cpp core/utilityz/utilityz.cpp -lcurl -lcrypto -lwebsockets -lbinacpp -ljsoncpp


///g++ -fconcepts-ts -I../3rd_party/binacpp/lib/libbinacpp/include t_json.cpp binace_contoler/binance_mgmt.cpp core/utilityz/utilityz.cpp analytic/analytic_processor_MCP.cpp -lcurl -lcrypto -lwebsockets -lbinacpp -ljsoncpp
#include <json/json.h>

#include "../3rd_party/binacpp/lib/libbinacpp/include/binacpp.h"
#include "../3rd_party/binacpp/lib/libbinacpp/include/binacpp_websocket.h"
#include <json/json.h>


#include "binace_contoler/binance_mgmt.hpp"
#include "core/utilityz/enumz_et_defultz.hpp"
#include "core/utilityz/utilityz.hpp"
#include "core/utilityz/timez.hpp"

#include "core/price_point_cmder.hpp"
#include "analytic/analytic_processor_MCP.hpp"

#define DEBUG_01

int main(int argc, char** argv)
{		

	//ticker_notify yf;
	
	analytic_processor an_proc;

	an_proc.startup();
an_proc.mprice_cmder.create_price_alert(Symbol_Tag::MATIC_BUSD,1.3100,false);
an_proc.mprice_cmder.create_price_alert(Symbol_Tag::MATIC_BUSD,1.2970,true);
bool stop = false;
char loop_n; 
while(!stop)
{
	an_proc.cycle_prices_alerts(an_proc.mprice_cmder.alert_price_begin(),an_proc.mprice_cmder.alert_price_end());
	std::cout <<"\nloop? n::";
	std::cin >> loop_n;
	if(loop_n == 'n')
		{stop = true;}
}

return 0;

}

/*

	binance_mgmt m_bi_mgmt;
	Symbol_Tag stag;
	m_bi_mgmt.startup(api_key,secret_key);

	price_point_dl pps_1_MI;
	 pps_1_MI = m_bi_mgmt.get_pp_dl(Utility::Symbol_Tag_to_string(Symbol_Tag::MATIC_BUSD));


	 std::cout <<"##_> gatherd from price raw data:price:::"<< pps_1_MI.price << '\n'
	 <<"::DATE::" <<  pps_1_MI.time_point <<  "\n\n***********"
	 << "serverTIME:: "<<m_bi_mgmt.server_time() << "\n\n************";

		//Json::Value result; 
	//	BinaCPP::init( api_key , secret_key );
	 //price_cmder pc;
	 */