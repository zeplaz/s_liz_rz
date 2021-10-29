
#ifndef SLIZERZ_YAHOOFINACE_CURL_01_HPP
#define SLIZERZ_YAHOOFINACE_CURL_01_HPP

#include <string>
#include <vector>

//#include <utility>

typedef std::string Q_Key;

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


enum interval_index
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


#endif
