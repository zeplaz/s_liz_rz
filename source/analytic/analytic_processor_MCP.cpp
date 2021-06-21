//analytic_processor_CMP.cpp


#include "analytic_processor_MCP.hpp"
//#include "../core/price_point_cmder.hpp"


void analytic_processor::startup()
{	
	std::string api_key     = API_KEY;
	std::string secret_key 	= SECRET_KEY;
	//should lunch login for binace. 
	mbinac_mgmt.startup(api_key,secret_key);
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