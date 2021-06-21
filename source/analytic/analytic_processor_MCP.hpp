//analytic_processor_MCP


#ifndef SLAZERZ_01_ANALYTIC_PROCESSOR_MCP_001_HPP
#define SLAZERZ_01_ANALYTIC_PROCESSOR_MCP_001_HPP


#include "../core/utilityz/enumz_et_defultz.hpp"
#include "../core/price_point_cmder.hpp"
#include "../binace_contoler/binance_mgmt.hpp"
#include "../core/utilityz/timez.hpp"
//#include <unordered_map> 

#include "../../../kez/s_kez.hpp"
//class gui_mgmt; 
//class binance_mgmt;
//class price_cmder;
class analytic_processor
{
	private :  

	// gui_mgmt* ptr_gui_mgmt = nullptr; 
	 binance_mgmt mbinac_mgmt;
	 

	//
//	void add_price_watch(Symbol_Tag const& in_sym);
	//void add_price_alert(Symbol_Tag const& in_sym, double price, bool is_low);

	//void add_notifcation_on_ticker(const Symbol_Tag& in_sym, long interval);
	public :
	price_cmder mprice_cmder;

	
	void update_ticker_notify();
	void update_price_list();

	void startup()
{	
	std::string api_key     = API_KEY;
	std::string secret_key 	= SECRET_KEY;
	//should lunch login for binace. 
	mbinac_mgmt.startup(api_key,secret_key);
}

	void cycle_prices_alerts(fl_ap_it itbegin, fl_ap_it itend)
	{	
		/*
			this is to expesive here, in a loop calling the prices? descaritng collect the whole list, at once
			time stamp it and then check its age... keep a bank of prices updated. regulary and THEN process, all
			some speifc tasks may require a "live" update keep that in mind.
			*/
		///get all prices;
		mbinac_mgmt.update_all_prices(mprice_cmder.current_price);
		long time = mprice_cmder.get_cashed_time();
		for (auto it = itbegin; it != itend; it++)
		{	
			
			//price_point_dl pp;
			double pp = mprice_cmder.get_cashed_price(it->first);
			//pp = mbinac_mgmt.get_pp_dl(Utility::Symbol_Tag_to_string(it->first));
			
			if(!it->second.past_threashold)
			{	
				#ifdef DEBUG_01 
					std::cout << "\n###---> not past_threasholded\n";
				#endif

				if(it->second.bellow)
				{	
					#ifdef DEBUG_01 
					std::cout << "\n###---> falling to alert\n";
					#endif
					if (pp < it->second.price)
					{	
						it->second.count++;
						it->second.last_occurance = time;// pp.time_point;
						it->second.past_threashold = true;
					
					#ifdef DEBUG_01 
					std::cout << "\n###---> price alart trigerd: falling\n"
					<<"it->second.count::" << it->second.count << "\n last occured::" << time <<"\n*****\n";
					#endif
					} 
				
				} 
				else
				{
					#ifdef DEBUG_01 
					std::cout << "\n###---> riseing to alert\n check if past::" << it->second.price << '\n';
					#endif
					if(pp > it->second.price)
					{
						it->second.count++;
						it->second.last_occurance = time;//pp.time_point;
						it->second.past_threashold = true;

					#ifdef DEBUG_01 
					std::cout << "\n###---> price alart rising trigerd: at::" << pp << '\n';
					#endif
					}
				}
			}
			else 
			{	
				
				if(it->second.bellow)
				{	
					std::cout << "\n###--->past_threasholded\n checking if price is greater then price\n"
					<< it->second.price << "where as price is" << pp << '\n';
					

					if (pp > it->second.price)
					{
					it->second.past_threashold=false;
					#ifdef DEBUG_01 
					std::cout << "\n###---> bellow == true, past_threashold=false";
					#endif
					}	
				}
				else
				{
					if (pp < it->second.price)
					{	
						std::cout << "\n###--->past_threasholded\n checking if price is lessthen then price\n"
						<< it->second.price << "where as price is" << pp << '\n';

						it->second.past_threashold=false;
					#ifdef DEBUG_01 
					std::cout << "\n###---> bellow == false, past_threashold=false";
					#endif
					}	
				}	
				
			}
			}
	}
///TODO:

	void open_chart(const Symbol_Tag&  in_sym);
	//void add_techical(Tech_Tag in_tag, Symbol_Tag in_symb);


/*
void cycle_prices_alerts(const fl_ap_it&  it, const riseing_tag& rt) {
    
}


void cycle_prices_alerts(const fl_ap_it&, const falling_tag& ft) {
    
}(/

	/*
	inline void set_gui_api(gui_mgmt const* in_gui)
	{
		ptr_gui_mgmt = gui_mgmt;
	}	
	*/
	

}; 


#endif