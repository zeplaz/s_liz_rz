///testjson

//g++ -fconcepts-ts -I../3rd_party/binacpp/lib/libbinacpp/include t_json.cpp binace_contoler/binance_mgmt.cpp core/utilityz/utilityz.cpp -lcurl -lcrypto -lwebsockets -lbinacpp -ljsoncpp
///g++ -fconcepts-ts -I../3rd_party/binacpp/lib/libbinacpp/include t_json.cpp binace_contoler/binance_mgmt.cpp core/utilityz/utilityz.cpp analytic/analytic_processor_MCP.cpp -lcurl -lcrypto -lwebsockets -lbinacpp -ljsoncpp
//// g++ -std=c++20 -pg -fconcepts-ts -I../3rd_party/binacpp/lib/libbinacpp/include -I../3rd_party t_json.cpp binace_contoler/binance_mgmt.cpp core/utilityz/locks.cpp core/price_point_cmder.cpp core/utilityz/utilityz.cpp -lcurl -lcrypto -lwebsockets -lbinacpp -ljsoncpp -lpthread


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

#include "core/tasker.hpp"
#include <thread>


#define DEBUG_01


inline static int keep_run = true; 

class background_priceupdate
{
public : 
 analytic_processor* in_ap;
 bool is_set = false; 

void process()
{	
		std::cout << "##-->>process:backgound pficeupdate\n";
	if(is_set)
	{
	while(keep_run)
	{
	std::cout << "\n*!*!*!*##-->>process:backgound::n_ap->update_prices();\n";	
	}
	} 
}
void update()
{
		in_ap->update_prices();	
}

void set_anly_proc(analytic_processor* ap_in)
{
	in_ap = ap_in;
	is_set = true;
}


void operator()()
{	
	this->process();
}

};



int main(int argc, char** argv)
{		

	//ticker_notify yf;
	
	analytic_processor an_proc;
	an_proc.startup();
	
	//utility::lock_price_Map.lock();
	an_proc.update_prices();
	//utility::lock_price_Map.unlock();
	std::cout << "update_prices movethough";

	background_priceupdate ojb_bg_price_updater;
	ojb_bg_price_updater.set_anly_proc(&an_proc);

	//tf::Task taskf_price_update = tf::Task(ojb_bg_price_updater);
	
	//utili_task::taskflow.emplace(taskf_price_update);



	//utili_task::executor.run(utili_task::taskflow);
	//background_priceupdate bg_price_update_functor;
	//std::thread p_update_thread(std::ref();
//
	//std::thread price_update_thread(ojb_bg_price_updater);


an_proc.mprice_cmder.create_price_alert(MATIC_BUSD,1.2200,false);
an_proc.mprice_cmder.create_price_alert(MATIC_BUSD,1.2370,true);
an_proc.mprice_cmder.create_price_alert(MATIC_BUSD,1.1200,false);
an_proc.mprice_cmder.create_price_alert(MATIC_BUSD,1.250,true);
an_proc.mprice_cmder.create_price_alert(MATIC_BUSD,1.3100,false);
an_proc.mprice_cmder.create_price_alert(MATIC_BUSD,1.2270,true);


an_proc.mprice_cmder.create_price_floor(MATIC_BUSD,1.210);
an_proc.mprice_cmder.create_price_floor(MATIC_BUSD,1.230);
an_proc.mprice_cmder.create_price_floor(MATIC_BUSD,1.2210);

an_proc.mprice_cmder.create_price_roof(MATIC_BUSD,1.1);
an_proc.mprice_cmder.create_price_roof(MATIC_BUSD,1.3270);
an_proc.mprice_cmder.create_price_roof(MATIC_BUSD,1.22);




bool stop = false;
char loop_n; 
int i = 0;

std::cout << "\n-----------------------------cycle_prices_alerts::" << '\n';
auto start01 = chrono::high_resolution_clock::now();



while(!stop)
{
	an_proc.cycle_prices_alerts(an_proc.mprice_cmder.alert_price_begin(),an_proc.mprice_cmder.alert_price_end());
	/*std::cout <<"\nloop? n::";
	std::cin >> loop_n;
	if(loop_n == 'n')
	{stop = true;}*/
	i++;
	if(i == 2)
	{stop = true;}

	
}

auto end01 = chrono::high_resolution_clock::now();

i = 0; 
stop = false;

std::cout << "\n-----------------------------cycle_prices_alerts_redux::" << '\n';
auto start02 = chrono::high_resolution_clock::now();
while(!stop)
{
	i++;
	an_proc.cycle_prices_alerts_redux();
	if(i == 2)
		{stop = true;}
}

keep_run = false; 
auto end02 = chrono::high_resolution_clock::now();

chrono::duration<double> diff = end01-start01;
	
	std::cout << "time_dif1::cycle_prices_alerts::" << diff.count() << '\n';

	diff = end02-start02;
	std::cout << "time_dif2::cycle_prices_alerts_redux::" << diff.count() << '\n';
	//courrent_low = diff.count();


//if (price_update_thread.joinable())
//price_update_thread.join();

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