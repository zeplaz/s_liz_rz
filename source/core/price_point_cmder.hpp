


//price_point_cmder
#ifndef SLAZERZ_01_PRICE_POINT_CMDER_001_HPP
#define SLAZERZ_01_PRICE_POINT_CMDER_001_HPP


#include <forward_list>
#include <queue>

#include "utilityz/enumz_et_defultz.hpp"
#include "compoent_stucts.hpp"


struct symb_price
{
Symbol_Tag tag;
double price;
};

struct ticker_notify{
	Symbol_Tag symb;
	Period_Mili period;
	long kickedoff_time;

	bool operator <(ticker_notify& rhs)
	{
		return  (kickedoff_time-period) < (rhs.kickedoff_time-rhs.period); 
	}
};


typedef std::pair<Symbol_Tag,threshold_price> threshold_pair;

typedef std::forward_list<threshold_pair>::iterator fl_tp_it;


class price_cmder
{
	private:
	std::priority_queue<ticker_notify> ticker_notify_pq;
	

	std::forward_list<threshold_pair> fl_alert_p_roof;
	std::forward_list<threshold_pair> fl_alert_p_floor;
	public:
	allprices current_prices;
	

		/*####LOCK USE:::lock_price_Map, for 
	call; std::unordered_map<Symbol_Tag,double>::const_iterator got = current_price.price_by_symb.find(in_tag);*/
	double get_cashed_price(const Symbol_Tag& in_tag); 

	void create_price_roof(const Symbol_Tag& in_tag, double price);

	void create_price_floor(const Symbol_Tag& in_tag, double price);

	void add_ticker_notify(const Symbol_Tag& in_tag, Period_Mili interval);

	inline fl_tp_it alert_price_roof_begin()
	{
		return fl_alert_p_roof.begin();
	}

	inline fl_tp_it alert_price_roof_end()
	{
		return fl_alert_p_roof.end();
	}

	inline fl_tp_it alert_price_floor_begin()
	{
		return fl_alert_p_floor.begin();
	}

	inline fl_tp_it alert_price_floor_end()
	{
		return fl_alert_p_floor.end();
	}


	inline long get_cashed_time()
	{
		return current_prices.last_update.load(std::memory_order_acquire);
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
