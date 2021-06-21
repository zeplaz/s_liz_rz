//analytic_processor_MCP


#ifndef SLAZERZ_01_ANALYTIC_PROCESSOR_MCP_001_HPP
#define SLAZERZ_01_ANALYTIC_PROCESSOR_MCP_001_HPP


#include "../core/utilityz/enumz_et_defultz.hpp"
#include "../core/price_point_cmder.hpp"
#include "../binace_contoler/binance_mgmt.hpp"
#include "../core/utilityz/timez.hpp"
//#include <unordered_map> 


//class gui_mgmt; 
//class binance_mgmt;
//class price_cmder;
class analytic_processor
{
	public :  

	// gui_mgmt* ptr_gui_mgmt = nullptr; 
	 binance_mgmt mbinac_mgmt;
	 price_cmder mprice_cmder;

	//
//	void add_price_watch(Symbol_Tag const& in_sym);
	//void add_price_alert(Symbol_Tag const& in_sym, double price, bool is_low);

	//void add_notifcation_on_ticker(const Symbol_Tag& in_sym, long interval);
	void update_ticker_notify();
	void update_price_list();
	
	void cycle_prices_alerts(fl_ap_it itbegin, fl_ap_it itend)
	{	



		///get all prices;

		for (auto it = itbegin; it != itend; it++)
		{	
			/*
			this is to expesive here, in a loop calling the prices? descaritng collect the whole list, at once
			time stamp it and then check its age... keep a bank of prices updated. regulary and THEN process, all
			some speifc tasks may require a "live" update keep that in mind.
			*/price_point_dl pp;
			
			pp = mbinac_mgmt.get_pp_dl(Utility::Symbol_Tag_to_string(it->first));
			
			if(!it->second.past_threashold)
			{	
				#ifdef DEBUG_01 
					std::cout << "\n###---> not past_threasholded\n";
				#endif

				if(it->second.bellow)
				{	
					#ifdef DEBUG_01 
					std::cout << "\n###---> falling to alertl\n";
					#endif
					if (pp.price < it->second.price)
					{	
						it->second.count++;
						it->second.last_occurance = pp.time_point;
					
					#ifdef DEBUG_01 
					std::cout << "\n###---> price alart trigerd: rising\n";
					#endif
					} 
				
				} 
				else
				{
					#ifdef DEBUG_01 
					std::cout << "\n###---> riseing to alertl\n";
					#endif
					if(pp.price > it->second.price)
					{
						it->second.count++;
						it->second.last_occurance = pp.time_point;

					#ifdef DEBUG_01 
					std::cout << "\n###---> price alart trigerd:";
					#endif
					}
				}
			}
			else 
			{	

				
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