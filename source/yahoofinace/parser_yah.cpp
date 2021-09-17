

#include "yf_curl.hpp"

#include "../core/utilityz/errorhandler.hpp"


quote_yah parser_quote_yah::get_quote(std::string symbol, int range, int granulity)
{
	
	quote_yah quote(symbol); 

	ERRORCODE  res = this->parse_quote(quote,curl_hand.get_rawQuote(symbol,range,granulity));

	#ifdef DEBUG_01
	fmt::print("\n ##-->parser_quote_yah::get_quote ERROCODE:: {} \n ", res);	
	#endif

	return quote;
}

int parser_quote_yah::extact_intger(size_t& pos, std::string const& data)
	{	
		fmt::print("\n ##-->extact_intger \n ");	
		char n_char = ' ';
		
		std::string temp_int = " ";
	
		n_char = data.at(pos);
		

		#ifdef DEBUG_02	
		fmt::print("\n ##-->n_char BEFORE commacheck::{} \n",n_char);	
		#endif
		if(n_char == comma)
		{
			pos++;
			n_char = data.at(pos);
		}
		#ifdef DEBUG_02	
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


	double parser_quote_yah::extact_double(size_t& pos, std::string const& data)
	{
		fmt::print("\n ##-->extact_double \n ");	
		char n_char = ' ';
		
		std::string temp_dub = " ";
	
		n_char = data.at(pos);


		while(n_char !=comma)
		{	
			temp_dub += n_char; 
			if(data.at(pos+1) == delimitEnd ||pos == data.size())
				break;
			
			pos++;
			n_char = data.at(pos);
		
		}
		fmt::print("CURRENT::TEMP:double::{}\n",temp_dub);
		return std::stod(temp_dub);
	}


std::vector<double> parser_quote_yah::get_varyable_double(std::string const& tag ,size_t being_pos , std::string const& data)
{

	fmt::print("\n ##-->get {} \n ", tag);

		char n_char = ' '; 
		std::vector<double> var;
		size_t pos = being_pos;

		if (data.at(being_pos) == colon && data.at(being_pos+1) == delimitBeing)
			pos= pos+2; 
		else 
		{	
			Utility::Print_Error(YAHOO_CURL_PARSE_FAIL,LV2,"##get_varyable_double with taged invalid formate!");
			return var;

		}	

	
		while(n_char!=delimitEnd)
		{
			{
			 var.push_back(extact_intger(pos,data));
			}
			pos++; 
			n_char = data.at(pos);
			
			if(pos == data.size())
				break;
		}
		return var; 		

}

std::vector<int> parser_quote_yah::get_timestamps(size_t being_pos, std::string const& data)
	{	

		fmt::print("\n ##-->get_timestamps \n ");

		char n_char = ' '; 
		std::vector<int> tsamp;
		size_t pos = being_pos;
		#ifdef DEBUG_02
		fmt::print("\n ##-->pos::{}, pos+1:: {}, post+2::{}, \n",data.at(pos), data.at(pos+1), data.at(pos+2));
		#endif

		if (data.at(being_pos) == colon && data.at(being_pos+1) == delimitBeing)
			pos= pos+2; 
		else 
		{	
			Utility::Print_Error(YAHOO_CURL_PARSE_FAIL,LV2,"Timesamp:: inproper delmit being formate!");
			return tsamp;

		}	
			
		#ifdef DEBUG_02
		fmt::print("\n ##-->pos::{} \n",pos);
		#endif

		while(n_char!=delimitEnd)
		{
			{
			 tsamp.push_back(extact_intger(pos,data));
			}
			pos++; 
			n_char = data.at(pos);

		}
		

		return tsamp;	
	}


ERRORCODE parser_quote_yah::parse_quote(quote_yah& out_quote, std::string const& rawdata)
	{
		
//			char delim; 
		 	
		fmt::print("\n ##-->parse_quote \n ");	

		bool failed = false; 

		std::size_t  ts_pos = rawdata.find(timestamp_tag);
		std::vector<int>  tsampvec;
		std::vector<double>  close_vec;
		std::vector<double>  open_vec;
		std::vector<double>  high_vec;
		std::vector<double>  low_vec;
		std::vector<double>  vol_vec;


		if(ts_pos!=std::string::npos)
		{
			tsampvec= get_timestamps(ts_pos+timestamp_tag.size(),rawdata);
		#ifdef DEBUG_01
			fmt::print("DEBUGFOR::parse_quote::get_timestamps,contanersize:: {}\n", tsampvec.size());
		#endif		
		}
		else
		{
			failed = true; 
		}	
		
		std::size_t  close_pos = rawdata.find(close_tag);
		if(close_pos!=std::string::npos)
		{
			close_vec= get_varyable_double(close_tag,close_pos+close_tag.size(),rawdata);
		#ifdef DEBUG_01
			fmt::print("DEBUGFOR::parse_quote::get_varyable_double tag:{} contanersize:: {}\n", close_tag, close_vec.size());
		#endif				
		}
		else
		{
			failed = true; 
		}	
		
		std::size_t  open_pos = rawdata.find(open_tag);
		if(open_pos!=std::string::npos)
		{
				
			open_vec= get_varyable_double(open_tag,open_pos+open_tag.size(),rawdata);
		#ifdef DEBUG_01
			fmt::print("DEBUGFOR::parse_quote::get_varyable_double tag:{} contanersize:: {}\n", open_tag, open_vec.size());
		#endif		
		}
		else
		{
			failed = true; 
		}	
		std::size_t  high_pos = rawdata.find(high_tag);
		if(high_pos!=std::string::npos)
		{
			high_vec= get_varyable_double(high_tag,high_pos+high_tag.size(),rawdata);
		#ifdef DEBUG_01
			fmt::print("DEBUGFOR::parse_quote::get_varyable_double tag:{} contanersize:: {}\n", high_tag, high_vec.size());
		#endif		
		}
		else
		{
			failed = true; 
		}	
		std::size_t  low_pos = rawdata.find(low_tag);
		if(low_pos!=std::string::npos)
		{
			low_vec= get_varyable_double(low_tag,low_pos+low_tag.size(),rawdata);
		#ifdef DEBUG_01
			fmt::print("DEBUGFOR::parse_quote::get_varyable_double tag:{} contanersize:: {}\n", low_tag, low_vec.size());
		#endif				
		}
		else
		{
			failed = true; 
		}	

		std::size_t  vol_pos = rawdata.find(volume_tag);
		if(vol_pos!=std::string::npos)
		{
			vol_vec= get_varyable_double(volume_tag,vol_pos+volume_tag.size(),rawdata);
		#ifdef DEBUG_01
			fmt::print("DEBUGFOR::parse_quote::get_varyable_double tag:{} contanersize:: {}\n", volume_tag, vol_vec.size());
		#endif				
		}
		else
		{
			failed = true; 
		}	


		if(failed == true)
		{
			Utility::Print_Error(YAHOO_CURL_PARSE_FAIL,LV2);
			return YAHOO_CURL_PARSE_FAIL;	
		}

		if((vol_vec.size() != low_vec.size()) && (high_vec.size() != close_vec.size()) && (open_vec.size() != tsampvec.size()))
		{
			Utility::Print_Error(PARSE_VEC_SIZE_MISSMATCH,LV2);
			return PARSE_VEC_SIZE_MISSMATCH;	
		}

		for(size_t i = 0; i < tsampvec.size(); i++)
		{
			spot_yah nspot(tsampvec.at(i),open_vec.at(i),close_vec.at(i),high_vec.at(i), low_vec.at(i),vol_vec.at(i));
			out_quote.add_spot(nspot);	
			 
		}

		return NO_ERROR; 
	}	