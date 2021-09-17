//quote_yah

#include "yf_curl.hpp"

#include "../core/utilityz/errorhandler.hpp"


quote_yah::quote_yah(std::string s)
	{
		this->symbol = s;
	}


spot_yah::spot_yah(time_t d, double o, double c, double h, double l, int v)
{
	this->date = d; 
	this->open = o;
	this->close = c;
	this->high = h;
	this->low = l; 
	this->volume = v;
}

std::string spot_yah::to_string()
{
	return   fmt::format("Date: {}",ctime(&date))+
			 fmt::format("Open: {} \n",open)+
			 fmt::format("Close: {} \n",close)+
			 fmt::format("High: {} \n",high)+
			 fmt::format("Low: {} \n",low);
}	
