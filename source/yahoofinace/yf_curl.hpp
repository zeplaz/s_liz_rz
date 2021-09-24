
#ifndef SLIZERZ_YAHOOFINACE_CURL_01_HPP
#define SLIZERZ_YAHOOFINACE_CURL_01_HPP

#include <string>
#include <vector>

#include "../core/utilityz/error_MSG.hpp"

const std::string y_qoute_url = "https://finance.yahoo.com/quote/";
const std::string query_chart_url= "https://query1.finance.yahoo.com/v7/finance/chart/";

const std::vector<std::string> ranges_period{"1d","5d","1mo","3mo","6mo","1y", "2y,""5y","10y","ytd","max"};
const std::vector<std::string> granualrity{"1m","5m","15m","60m","90m","1h","1d", "1wk", "1mo", "3mo"};

const std::string range_tag          ="?range=";
const std::string interval_tag       ="&interval=";
const std::string  incator_timestamp = "&indicators=quote&includeTimestamps=true";

const std::string timestamp_tag = ",\"timestamp\"";
const std::string close_tag = "\"close\"";
const std::string open_tag = "\"open\"";
const std::string high_tag = "\"high\"";
const std::string low_tag = "\"low\"";
const std::string volume_tag = "\"volume\"";

const std::string r_marketTime     ="regularMarketTime";
const std::string r_marketPrice    ="regularMarketPrice";
const std::string chart_prev_close ="chartPreviousClose";
const std::string prev_close       ="previousClose";

const char delimitBeing = '[';
const char delimitEnd = ']';
const char colon = ':';
const char comma = ',';


enum inveral_index 
{
	i1d,
	i5d,
	i1mo,
	i3mo,
	i6mo,
	i1y,
	i2y,
	i5y,
	i10y,
	ytd,
	max
};


enum granuality_index
{
	g1m,
	g5m,
	g15m,
	g60m,
	g90m,
	g1h,
	g1d,
	g1wk,
	g1mo,
	g3mo
};

struct quote_pak
{
	int interval;
	int granulity;
};

/*
 ***spot_yah***
  DEFINED IN::->parser_yah.cpp
*/
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
  DEFINED IN::->parser_yah.cpp
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

struct curl_handler
{

	std::string get_rawQuote(std::string symbol, int range, int granulity);

	inline static size_t writeCallback(char *content, size_t size, size_t nmemb, void *userdata)
		 {
	    // Append the content to user data
	    ((std::string*)userdata)->append(content, size * nmemb);

	    // Return the real content size
	    return size * nmemb;
	}

};

/*
 ***parser_quote_yah***
 handles string filled with the raw yahoo finace quote data 
 as produced curl from quote_yah::quote(int range, int intveral). 
 parses and though the passed quote ref fills it with the spots.

 DEFINED IN::->parser_yah.cpp
*/

struct parser_quote_yah
{	
private:
	curl_handler curl_hand;

	int extact_intger(size_t& pos, std::string const& data);
	double extact_double(size_t& pos, std::string const& data);

	std::vector<int>    get_timestamps(size_t being_pos , std::string const& data);
	std::vector<double> get_varyable_double(std::string const& tag ,size_t being_pos , std::string const& data);
	ERRORCODE parse_quote(quote_yah& out_quote, std::string const& rawdata);
public: 
	quote_yah get_quote(std::string symbol,int range, int interval);
};







#endif