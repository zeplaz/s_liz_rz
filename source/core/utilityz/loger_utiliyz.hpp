//logger


#ifndef SLAZERZ_01_LOGER_UTILITY_001_HPP
#define SLAZERZ_01_LOGER_UTILITY_001_HPP

//enum class Symbol_Tag: uint32_t;
//std::string Symbol_Tag_to_string(Symbol_Tag in_tag); //->DEFINED IN:
//Symbol_Tag  string_to_symbol(std::string symbol);


#include <atomic>
#include <mutex>


namespace Utility 
{

enum class Systems_Online : uint32_t;

typedef unsigned char ERROR_FLAG;  

//std::string which_systems(Systems_Online sym_comp);


struct logger
{
	
// list active sysems?

		protected : 
	logger() = default;
	logger(const logger&) = delete; 
	logger& operator=(const logger&) = delete; 
	logger(logger&&) = delete;
	logger& operator=(logger&&) = delete; 
	//outputtime.

	static std::atomic<logger*> instance; 
	static std::mutex logger_mutex;

	bool print_on_Errorcode = false; 

	std::atomic<ERRORCODE> last_ERRORCODE;
	std::atomic<ERRORFLAG> error_status; 


	public : 

	static logger* get_instance(); 

	inline void set_errorflag(ERROR_FLAG in_ec)
	{
		error_status = in_ec; 
	}

	inline void store_errorcoode( in_ef)
	{
		
		std::lock_guard<std::mutex> guard(logger_mutex);
		if(print_on_Errorcode == true)
		{
			print_error_log(last_ERRORCODE.exchange(in_ef));
		}
		else
		{
			last_ERRORCODE.store(in_ef); 
		}
		
	} 



	void poll_errlog();

	void print_error_log();
	void print_error_log(auto extra_data)
	{

		fmt::print
		(
			"::##__>ERROR_Log::"
			

		);
	}

	void set_write_to_console();
	void set_write_to_file();

	void set_write_file(std::string file);

};
}

#endif

