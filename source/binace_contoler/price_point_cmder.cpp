//price_point_cmder.cpp


#include "price_point_cmder.hpp"
#include "../core/utilityz/locks.hpp"
//

#include <iostream>

	
double price_cmder::get_cashed_price(const Symbol_Tag& in_tag)
	{	
/*---------------------------------------CRTICAL SECTION-------------------------------------------------------------------------*/
		std::cout << "\n!@-CRTICAL SECTION:: price_cmder::get_cashed_price(::lock_price_Map\n";
		utility::lock_price_Map.lock();
	//	utility::lock_price_semaphore.acquire();
		std::unordered_map<Symbol_Tag,double>::const_iterator got = current_prices.price_by_symb.find(in_tag);

	 if ( got == current_prices.price_by_symb.end())
	 {	
	 	utility::lock_price_Map.unlock();
	//   utility::lock_price_semaphore.release();
/*--------------------------------------------#END-------------------------------------------------------------------------------*/	 
	 	#ifdef DEBUG_01
	    std::cerr << "##NOTFOUND-->get_cashed_price::current_price::not found\n";
	 	#endif
	 	return -1.0;
	 }
	 else 
	 {	utility::lock_price_Map.unlock();
	 	 //utility::lock_price_semaphore.release();	
	 	return got->second;
	 }
     utility::lock_price_Map.unlock();
//	 utility::lock_price_semaphore.release();	
/*--------------------------------------------#END-------------------------------------------------------------------------------*/	 
	  return -1.1;

	 }



void price_cmder::create_price_roof(const Symbol_Tag& in_tag, double price)
	{
		#ifdef DEBUG_01
		std::cout << "\n###----<<<>>>>>create_price_thresholder::roof\n";
		#endif
		threshold_price tp;
		tp.price = price;

		fl_alert_p_roof.emplace_front(in_tag,tp);
	}

void price_cmder::create_price_floor(const Symbol_Tag& in_tag, double price)
	{
		#ifdef DEBUG_01
		std::cout << "\n###----<<<>>>>>create_price_thresholder::floor\n";
		#endif
		threshold_price tp;
		tp.price = price;

		fl_alert_p_floor.emplace_front(in_tag,tp);
	}