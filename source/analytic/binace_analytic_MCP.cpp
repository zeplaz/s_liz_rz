//analytic_processor_CMP.cpp


#include "binance_analytic_MCP.hpp"
//#include "../core/price_point_cmder.hpp"
//#include "../binace_contoler/binance_mgmt.hpp"

#include "../../../kez/s_kez.hpp"

#ifdef DEBUG_01
#include <iostream>
#endif




void binace_analytic_MCP::background_binance_oprator::binance_startup()
   {
    std::string api_key     = API_KEY;
    std::string secret_key  = SECRET_KEY;
  
    mbinac_mgmt.startup(api_key,secret_key);
   }

    
  void binace_analytic_MCP::background_binance_oprator::operator()()
  { 
    binance_startup();

    while(keep_binance_runing)
    {
      update_prices();
    }
  }

  void binace_analytic_MCP::background_binance_oprator::update_prices()
  {
  	mbinac_mgmt.update_all_prices(mprice_cmder.current_prices);
    prices_updated.store(true,std::memory_order_release);
    last_price_update.store(mprice_cmder.get_cashed_time(),std::memory_order_release);

   
  }



void binace_analytic_MCP::cycle_prices_alerts_redux()
	{
		if(back_binace_oper.prices_updated.load(std::memory_order_acquire))
		{
			#ifndef DEBUG_01
			std::cout << "||-> cycle price alerts; load prices updated \n";
			#endif
			back_binace_oper.prices_updated.store(false,std::memory_order_release);
			long time = mprice_cmder.get_cashed_time();
			
			cycle_price_roofs(time);
		  cycle_price_floors(time);
		}	 
	}

	void binace_analytic_MCP::threshold_crossed(threshold_price* thresh_point, long t)
	{
		thresh_point->count++;
		thresh_point->last_occurance = t;
		thresh_point->past_threshold = true;

			#ifdef DEBUG_01 
			std::cout << "\n###---> price alart trigerd:\n"
			<<"it->second.count::" << thresh_point->count << "\n last occured::" << t <<"\n*****\n";
			#endif
	}   

	void binace_analytic_MCP::check_above_and_update(double pp,long t, threshold_price* thresh_point)
	{
		if(is_price_above_threshold(pp,thresh_point->price))
			{
				threshold_crossed(thresh_point,t);				
			}
	}

void binace_analytic_MCP::cycle_price_roofs(long t)
{
	
	for(auto it = mprice_cmder.alert_price_roof_begin(); it!= mprice_cmder.alert_price_roof_end();it++)
		{
			double pp = mprice_cmder.get_cashed_price(it->first);
			threshold_price* thresh_point = &it->second; 

			if(!thresh_point->past_threshold)
			{
				check_above_and_update(pp,t,thresh_point);
			}

			else
			{
					#ifdef DEBUG_01 
					std::cout << "\n###--->past_threasholded\n checking if price is greater then price\n"
					<< it->second.price << "where as price is" << pp << '\n';
					#endif	
				if(is_price_bellow_threshold(pp,thresh_point->price))
					thresh_point->past_threshold = false; 		
			}
			
		}
}


bool binace_analytic_MCP::is_price_above_threshold(double price, double thresh)
{
	if (price > thresh)
	{	
		return true;
	} 		 
	return false; 
}
			

bool binace_analytic_MCP::is_price_bellow_threshold(double price, double thresh)
{
	if (price < thresh)
	{
		return true;
	}
	return false; 	
}
	

void binace_analytic_MCP::cycle_price_floors(long t)
{
			for(auto it = mprice_cmder.alert_price_floor_begin(); it!= mprice_cmder.alert_price_floor_end() ;it++)
		{
			double pp = mprice_cmder.get_cashed_price(it->first);
			if(!it->second.past_threshold)
			{
				if (pp < it->second.price)
				{	
					it->second.count++;
					it->second.last_occurance = t;
					it->second.past_threshold = true;
					
					#ifdef DEBUG_01 
					std::cout << "\n###---> price alart trigerd: falling\n"
					<<"it->second.count::" << it->second.count << "\n last occured::" << time <<"\n*****\n";
					#endif
				} 	
			}
			else
			{	
				#ifdef DEBUG_01 
				std::cout << "\n###--->past_threasholded\n checking if price is greater then price\n"
				<< it->second.price << "where as price is" << pp << '\n';
				#endif		

				if (pp > it->second.price)
				{
					it->second.past_threshold=false;
					#ifdef DEBUG_01 
					std::cout << "\n###---> bellow == true, past_threashold=false";
					#endif
				}		
			}	
		}
}

		

/*
			this is to expesive here, in a loop calling the prices? descaritng collect the whole list, at once
			time stamp it and then check its age... keep a bank of prices updated. regulary and THEN process, all
			some speifc tasks may require a "live" update keep that in mind.
			*/
		///get all prices;
/*
	void cycle_prices_alerts(fl_ap_it itbegin, fl_ap_it itend)
	{	
		
		//mbinac_mgmt.update_all_prices(mprice_cmder.current_price);
		//this->update_prices();
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
					#ifdef DEBUG_01 
					std::cout << "\n###--->past_threasholded\n checking if price is greater then price\n"
					<< it->second.price << "where as price is" << pp << '\n';
					#endif

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
						#ifdef DEBUG_01 
						std::cout << "\n###--->past_threasholded\n checking if price is lessthen then price\n"
						<< it->second.price << "where as price is" << pp << '\n';
						#endif

						it->second.past_threashold=false;
					#ifdef DEBUG_01 
					std::cout << "\n###---> bellow == false, past_threashold=false";
					#endif
					}	
				}	
				
			}
			}
	}
/*
void analytic_processor::cycle_prices_alerts(fl_ap_it itbegin, fl_ap_it itend)
	{

		for (auto it = itbegin; it != itend; it++)
		{	
			price_point_dl pp;
			pp = mbinac_mgmt.get_pp_dl(Utility::Symbol_Tag_to_string(it->frist));
		
			if(!it->second.past_threashold)
			{
				if(it->second.bellow)
				{
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
				
		}
	}		
*/