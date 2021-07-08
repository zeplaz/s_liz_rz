
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
#include <atomic>

struct allprices{

	std::atomic<long> last_update; 

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

	bool past_threshold = false; 
	bool bellow = false;

};

struct threshold_price 
{	
	int count = 0;
	double price =0.0f;
	long last_occurance =0;

	bool past_threshold = false; 
};

//--------------------------------------------

const constexpr int FLOOR = -1;
const constexpr int ROOF  =  1;
struct riseing_tag {};
struct falling_tag {};
/*

template<typename T>
struct Price_Traits;

template<>
Price_Traits<riseing_tag>
{
	inline static int const Polarity = 1; 
};

template<>
Price_Traits<falling_tag>
{
	inline static int const Polarity = -1; 
};*/

#endif
/*

class Policy_Floor
{
	public :
	template<typename Itter>
	
	static void test_threshold(Itter i_begin, Itter i_end,long time)
	{
		#ifdef DEBUG_01 
		std::cout << "\n###::Policy_Floor::####\n\n###--->";
		#endif

		for (it = i_begin; it!= i_end; it++)
		{
			if(!it->second.past_threashold)
			{
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
		}
	}
};

class Policy_Roof
{
	public :

	template<typename Itter>
	static void test_threshold(Itter i_begin, Itter i_end, ,long time))
	{
		
		#ifdef DEBUG_01 
		std::cout << "\n###::Policy_Roof::####\n\n###--->";
		#endif
	

		for (it = i_begin; it!= i_end; it++)
		{
			if(!it->second.past_threashold)
			{
				if (pp > it->second.price)
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
				std::cout << "\n###--->past_threasholded\n checking if price is greater then price\n"
				<< it->second.price << "where as price is" << pp << '\n';
					

				if (pp < it->second.price)
				{
					it->second.past_threashold=false;
					#ifdef DEBUG_01 
					std::cout << "\n###---> bellow == true, past_threashold=false";
					#endif
				}		
			}	
		}
	}
};
*/


/*
template<typename Policy,typename Price_Traits>

class alert_check
{
void operator()()
	{
		Policy_Roof()	
	}
};
*/




/*



template<bool Is_Floor = false>
struct price_floor  


template<class Tag_type>
struct Tag{
	Tag_type tag;
};
constexpr if(Is_Floor == riseing_tag)
	{

	}
	template <>
struct traits {
    typedef riseing_tag tag;
};

template <bool T = 1>
struct traits<> {
    typedef falling_tag tag;
};*/