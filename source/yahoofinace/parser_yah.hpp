#ifndef SLAZERZ_01_PARSER_YAH_001_HPP
#define SLAZERZ_01_PARSER_YAH_001_HPP

/*
 ***parser_quote_yah***
 handles string filled with the raw yahoo finace quote data
 as produced curl from quote_yah::quote(int range, int intveral).
 parses and though the passed quote ref fills it with the spots.

 DEFINED IN::->parser_yah.cpp
*/

#include "curl_handler_yf.hpp"
#include "quote_spot_yah.hpp"

#include "../core/utilityz/errorhandler.hpp"

#include <vector>

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
