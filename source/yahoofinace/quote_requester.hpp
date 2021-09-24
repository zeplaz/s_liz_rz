//quote_requester.hpp

#ifndef SLIZERZ_YAHOOFINACE_QUOUTE_REQUESTER_01_HPP
#define SLIZERZ_YAHOOFINACE_QUOUTE_REQUESTER_01_HPP


#include <memory>

#include <atomic>
#include <condition_variable> // std::condition_variable
#include <mutex> 

#include <queue>
#include <unordered_map>

#include "yf_curl.hpp"
#include "../../3rd_party/stdext/atomic_shard_ptr.hpp"
#include "../core/utilityz/id_utilityz.hpp"


#include "../core/utilityz/errorhandler.hpp"

//class quote_bank : public std::vector<quote_yah>

struct quote_req_pak
{
	std::string symbol;
	int interval;
	int granulity;
};

typedef std::string Key;  
typedef std::shared_ptr<quote_yah> Quote_ptr; 

typedef std::unordered_map<std::string,Quote_ptr> Quote_Map; 

typedef int Quote_Status;

enum Q_stat
{
	FOUND,
	NOTFOUND,
	INQUE,
	ERROR
	
};

class quote_bank : public Quote_Map
{

	std::vector<std::string> key_bank;
public : 
	Q_Key get_last_key();
	Q_Key registar(quote_req_pak const& qrpak);
	Quote_Status retreive(Quote_ptr& out_quote , Q_Key const& k);
protected : 
	Q_Key make_key(quote_req_pak const& qrpak);
};


struct quote_request
{	
	
	std::string symbol;
	int interval;
	int granulity;

	std::atomic<std::shared_ptr<quote_bank>> dest_bank_ptr;
	//std::shared_ptr<quote_bank> dest_bank_ptr;
	
	quote_request(std::shared_ptr<quote_bank> dest, std::string sym, int i, int g);

	quote_request(quote_request&& other) noexcept
	{
		symbol = other.symbol;
		interval = other.interval;
		granulity = other.granulity;
		dest_bank_ptr.store(other.dest_bank_ptr.load()); 
		 
	}
};



class quote_requester
{

	parser_quote_yah pq; 
	std::queue<quote_request> que_q_req;
 
	public :

	std::atomic<bool> work_pending = false;

	std::condition_variable cv;
	std::mutex mtx;

	bool shutdown_signa = false;
	
	void process_next();
	Q_Key create_request(std::shared_ptr<quote_bank> dest_bank, std::string sym, int interval, int granulity);

	inline bool are_pending()
	{
		if(que_q_req.size()!=0)
		{	
			fmt::print("cv.notify_all();\n");
			work_pending.store(true);
			cv.notify_all();
			return true;
		}
		else
		{	
			fmt::print("work_pending.store(false);\n");
			work_pending.store(false);
			return false;
		}
	}

	inline size_t num_pending()
	{
		return que_q_req.size();
	}
	void shutdown()
	{	
		fmt::print("shutdown\n");
		shutdown_signa = true;
		cv.notify_all();
	}

};


class thread_quote_worker
{	

	public : 
	void operator()();
	quote_requester q_requester; 
};

#endif