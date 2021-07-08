//analytic_processor_MCP


#ifndef SLAZERZ_01_ANALYTIC_PROCESSOR_MCP_001_HPP
#define SLAZERZ_01_ANALYTIC_PROCESSOR_MCP_001_HPP


#include "../core/utilityz/enumz_et_defultz.hpp"
#include "../core/price_point_cmder.hpp"
#include "../binace_contoler/binance_mgmt.hpp"

#include <atomic>

//class price_cmder;
//class binance_mgmt;
class threshold_price; 



class analytic_MCP
{
	public: 
	class background_binance_oprator
  { 

  public : 
   inline static std::atomic<bool> keep_binance_runing{true};
   inline static std::atomic<long> last_price_update;

   inline static  std::atomic<bool> prices_updated{false};
   inline static std::atomic_flag af_lock = ATOMIC_FLAG_INIT;
   inline static std::atomic_flag p_update_flag = ATOMIC_FLAG_INIT;
 
  public: 

   void operator() ();
   void update_prices(); 
   void binance_startup();
  };

	public: 
	 
	  inline static price_cmder  mprice_cmder;	
	  inline static binance_mgmt mbinac_mgmt;
	  inline static background_binance_oprator back_binace_oper;

	private :  
	
	void cycle_price_roofs(long t);
	void cycle_price_floors(long t);
	
	void threshold_crossed(threshold_price* thresh_point, long t);
	void check_above_and_update(double pp,long t, threshold_price* thresh_point);

	bool is_price_above_threshold(double price, double thresh);
	bool is_price_bellow_threshold(double price, double thresh);
	
	public :
	
	void cycle_prices_alerts_redux();
	//void cycle_prices_alerts(fl_ap_it itbegin, fl_ap_it itend);

	//void update_prices_from_binance();

///TODO:

	void open_chart(const Symbol_Tag&  in_sym);
	//void add_techical(Tech_Tag in_tag, Symbol_Tag in_symb);
//    auto oldx = atomic_g.load;
      //while(!atomic_g.compare_exchange_weak(oldx,f(oldx)));

}; 




#endif


 