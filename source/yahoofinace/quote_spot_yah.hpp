

#ifndef SLIZERZ_QUOTE_SPOT_YAH_01_HPP
#define SLIZERZ_QUOTE_SPOT_YAH_01_HPP

#include <string>
#include <vector>
/*
 ***spot_yah***
  DEFINED IN::->quote_spot_yah.cpp
*/
struct parser_quote_yah;

struct quote_req_pak
{
	parser_quote_yah* pq;
	std::string symbol;
	int interval;
	int granulity;



	void set_parser(parser_quote_yah* in_pq)
	{
		pq= in_pq;
	}

	quote_req_pak(){}
	quote_req_pak(parser_quote_yah* pqy, std::string sym, int inr, int gran) :
	  						pq(pqy), symbol(sym), interval(inr), granulity(gran)
							 {}
};

struct spot_yah
{

	time_t date;
	double open;
	double close;
	double high;
	double low;
	int volume;
	spot_yah(time_t d, double o, double c, double h, double l, int v);

	std::string to_string();

};

/*
 ***quote_yah***
  DEFINED IN::->quote_spot_yah.cpp
*/
struct quote_yah
{
	private :
	quote_yah(){}

	public :
	std::string symbol;
	std::vector<spot_yah> spots;

	quote_yah(std::string s);

	inline size_t num_spots()
	{
		return spots.size();
	}

	inline void add_spot(spot_yah in_spot)
	{
		//needs locks. or somthing omg.
		spots.push_back(in_spot);
	}

	inline void clear_spots()
	{
		/// needs to be critial secion
	}

	quote_yah(quote_yah const& other);
	quote_yah(quote_yah const&&  other);


};
#endif
