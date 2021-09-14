
#ifndef SLIZERZ_YAHOOFINACE_CURL_01_HPP
#define SLIZERZ_YAHOOFINACE_CURL_01_HPP

#include <string>
#include <vector>

#include <curl/curl.h>

#include "../core/utilityz/errorhandler.hpp"


const std::string y_qoute_url = "https://finance.yahoo.com/quote/";
const std::string query_chart_url= "https://query1.finance.yahoo.com/v7/finance/chart/";

const std::vector<std::string> ranges_period{"1d","5d","1mo","3mo","6mo","1y", "2y,""5y","10y","ytd","max"};
const std::vector<std::string> granualrity{"1m","5m","15m","60m","90m","1h","1d", "1wk", "1mo", "3mo"};

const std::string range_tag          ="?range=";
const std::string interval_tag       ="&interval=";
const std::string  incator_timestamp = "&indicators=quote&includeTimestamps=true";




	const std::string timestamp_tag = ",\"timestamp\":[";
	const std::string close_tag = "\"close\"";
    const std::string open_tag = "\"open\"";
	const std::string high_tag = "\"high\"";
	const std::string low_tag = "\"low\"";


	const std::string r_marketTime     ="regularMarketTime";
	const std::string r_marketPrice    ="regularMarketPrice";
	const std::string chart_prev_close ="chartPreviousClose";
	const std::string prev_close       ="previousClose";

	const char delimitBeing = '[';
	const char delimitEnd = ']';
	const char colon = ':';
	const char comma = ',';

struct parser_quote{


	int extact_intger(size_t& pos, std::string const& data)
	{	
		fmt::print("\n ##-->extact_intger \n ");	
		char n_char = ' ';
		
		std::string temp_int = " ";
	
		n_char = data.at(pos);
		

		#ifdef DEBUG02	
		fmt::print("\n ##-->n_char BEFORE commacheck::{} \n",n_char);	
		#endif
		if(n_char == comma)
		{
			pos++;
			n_char = data.at(pos);
		}
		#ifdef DEBUG02	
		fmt::print("\n ##-->n_char BEFORE WHILE::{} \n",n_char);	
		#endif
			
		while(n_char !=comma)
		{	
			temp_int += n_char; 
			if(data.at(pos+1) == delimitEnd)
				break;
			
			pos++;
			n_char = data.at(pos);
		
		}
		fmt::print("CURRENT::TEMP:INT::{}\n",temp_int);
		return std::stoi(temp_int);
	}		

	std::vector<int> get_timestamps(size_t being_pos , std::string const& data)
	{	

		fmt::print("\n ##-->get_timestamps \n ");

		char n_char = ' '; 
		std::vector<int> tsamp;
		size_t pos = being_pos;
		if (data.at(being_pos+1) == colon && data.at(being_pos+2) == delimitBeing)
		pos= pos+3; 


		#ifdef DEBUG02
		fmt::print("\n ##-->pos::{} \n",pos);
		#endif
		{
		while(n_char!=delimitEnd)
		{
			{
			 tsamp.push_back(extact_intger(pos,data));
			}
			pos++; 
			n_char = data.at(pos);

		}
		}

		return tsamp;	
	}
	
	/*	
	std::vector<std::string> cleared_set(size_t being_pos ,std::sring& data, char dlimit)
	{
		char n_char = ''; 

		while(n_char!=delimtEnd)
		{
			if (data.at(being_pos+1) == colon && data.at(being_pos+2) == delimitBeing
			{

			}

		}	
	}*/



	bool take_raw(std::string const& rawdata)
	{
		
//			char delim; 
		 	
		fmt::print("\n ##-->take_raw \n ");	

		bool failed = false; 

		std::size_t  ts_pos = rawdata.find(timestamp_tag);
			
		if(ts_pos!=std::string::npos)
		{
			std::vector<int>  tsampvec= get_timestamps(ts_pos+timestamp_tag.size(),rawdata);
		#ifdef DEBUG01
			fmt::print("DEBUGFOR::takeRAW::Yahooparser,,,contanersize {}\n", tsampvec.size());
		#endif		
		}
		else
		{
			failed = true; 
		}	
		
		std::size_t  close_pos = rawdata.find(close_tag);
		if(close_pos!=std::string::npos)
		{
				
		}
		else
		{
			failed = true; 
		}	
		
		std::size_t  open_pos = rawdata.find(open_tag);
		if(open_pos!=std::string::npos)
		{
				
		}
		else
		{
			failed = true; 
		}	
		std::size_t  high_pos = rawdata.find(high_tag);
		if(high_pos!=std::string::npos)
		{
				
		}
		else
		{
			failed = true; 
		}	
		std::size_t  low_pos = rawdata.find(low_tag);
		if(low_pos!=std::string::npos)
		{
				
		}
		else
		{
			failed = true; 
		}	


		if(failed == true)
		{
			Utility::Print_Error(YAHOO_CURL_PARSE_FAIL,LV2);
			return false;	
		}
		return true; 
	}
};

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

struct y_spot
{
 
std::time_t date;
double open;
double close;
double high;
double low;

y_spot(std::time_t d, double o, double c, double h, double l)
{
	this->date = d; 
	this->open = o;
	this->close = c;
	this->high = h;
	this->low = l; 
}

std::string to_string()
{
//	std::ostringstream open_os; 
//	os << this->open;


	return 	fmt::format("Date: {}",ctime(&date))+
			fmt::format("Open: {} \n",open)+
			fmt::format("Close: {} \n",close)+
			fmt::format("High: {} \n",high)+
			fmt::format("Low: {} \n",low);
}	

};




struct y_quote
{	
	std::string symbol;
	std::vector<y_spot> spots;

	y_quote(std::string s)
	{
		this->symbol = s;
	}
	
	inline size_t num_spots()
	{
		return spots.size();
	} 

	

	std::string get_quote(int range, int intveral)
	{	

		std::string url = query_chart_url+this->symbol + 
					      range_tag + ranges_period.at(range) + 
					      interval_tag + granualrity.at(intveral) + 
					      incator_timestamp;



		//std::string sym_url = y_qoute_url+this->symbol  + "/?p="  + this->symbol;
		
		std::string responseBuffer;

		CURL* curl = curl_easy_init();
		
		if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());	

         curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
         curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseBuffer);

            // Perform the request
            CURLcode res = curl_easy_perform(curl);

            // Cleanup
            curl_easy_cleanup(curl);
    	}

    	return responseBuffer;
	}


	static size_t writeCallback(char *content, size_t size, size_t nmemb, void *userdata) {
    // Append the content to user data
    ((std::string*)userdata)->append(content, size * nmemb);

    // Return the real content size
    return size * nmemb;
}

};


#endif