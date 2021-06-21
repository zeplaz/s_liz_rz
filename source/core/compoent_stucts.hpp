
#ifndef SLAZERZ_01_COMPOENT_STUCTS_001_HPP
#define SLAZERZ_01_COMPOENT_STUCTS_001_HPP
//small structz.


//--------------------------------------------------------------------------||
/*
*
*                 >{binance_mgmt, analytic_processor, price_comander..}<
*
*/

//--------------------------------------------------------------------------||

#include "utilityz/enumz_et_defultz.hpp"

#include <unordered_map>

struct allprices{

	long last_update; 
	//std::unordered_map<std::string, double> price_by_symb;
	std::unordered_map<Symbol_Tag, double> price_by_symb;
};


//--------------------------------------------------------------------------||
/*
*
*                 >{analytic_processor, price_comander..}<
*
*/

//--------------------------------------------------------------------------||

struct alert_price 
{	
	int count = 0;
	double price =0.0f;
	long last_occurance =0;

	bool past_threashold = false; 
	bool bellow = false;

};



struct riseing_tag {};
struct falling_tag {};
/*
template <>
struct traits {
    typedef riseing_tag tag;
};

template <bool T = 1>
struct traits<> {
    typedef falling_tag tag;
};*/

#endif
