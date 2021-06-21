


//price_point_cmder
#ifndef SLAZERZ_01_PRICE_POINT_CMDER_001_HPP
#define SLAZERZ_01_PRICE_POINT_CMDER_001_HPP

//#include <utility>
//#include <algorithm>

#include <forward_list>
#include <queue>

#include <utility>

//#include <unordered_map>

//enum class Symbol_Tag : uint32_t;
//enum Period_Mili : long;
//inline static int next_ppp_ID = 0;
//typedef std::unordered_multimap<alert_pair> u_map_ap; 
#include "utilityz/enumz_et_defultz.hpp"
#include "compoent_stucts.hpp"
#ifdef DEBUG_01
#include <iostream>
#endif


struct ticker_notify{
	Symbol_Tag symb;
	Period_Mili period;
	long kickedoff_time;

	bool operator <(ticker_notify& rhs)
	{
		return  (kickedoff_time-period) < (rhs.kickedoff_time-rhs.period); 
	}
};




typedef std::pair<Symbol_Tag,alert_price> alert_pair; 
typedef std::forward_list<alert_pair>::iterator fl_ap_it;
struct price_cmder
{
	private:
	std::forward_list<alert_pair> fl_alert_p; 
	std::priority_queue<ticker_notify> ticker_notify_pq;
	allprices current_price_list;

	public:
	
	void create_price_alert(Symbol_Tag in_tag, double price, bool is_low)
	{
		#ifdef DEBUG_01
		std::cout << "\n###----<<<>>>>>create_price_alert\n";
		#endif

		alert_price wp;
		wp.price = price;
		wp.bellow = is_low;
		fl_alert_p.emplace_front( in_tag,wp);

	}
	void add_ticker_notify(Symbol_Tag in_tag, Period_Mili interval);
	
	inline fl_ap_it alert_price_begin()
	{
		return fl_alert_p.begin();
	}

		inline fl_ap_it alert_price_end()
	{
		return fl_alert_p.end();
	}


};


#endif

//std::vector<alert_price> get_symbols_watchlist(Symbol_Tag in_tag);
			
		/*
		std::pair <u_map_wp::iterator, u_map_wp::iterator> ret;
	    ret = p_watch_map.equal_range(in_tag);

	    #ifdef DEBUG_01
   	   // std::cout << Utility::Symbol_Tag_to_string(in_tag) << " =>";
	    #endif
	    std::vector<alert_price> wlist;

	    for (u_map_wp::iterator it=ret.first; it!=ret.second; ++it)
		{ 			
		  	wlist.push_back(it->second);
		}

		return wlist; 	
	}*/

/*
double& set_price(price_point_pair& p) { return p.first; }
clock_time_point& set_time(price_point_pair& p) { return p.second; }
double const& set_price(price_point_pair const& p) { return p.first; }
clock_time_point const& set_time(price_point_pair const& p) { return p.second; }
*/



/*
price_ltime make_plt_1(double p, clock_time_point ctp)
{

	return price_ltime(get_next_id_with_t(),std::make_pair(p,ctp.time_since_epoch().count()));
}


price_ltime make_plt_2(double p, clock_time_point ctp)
{

	return price_ltime(get_next_ppp_ID(),std::make_pair(p,ctp.time_since_epoch().count()));
}*/