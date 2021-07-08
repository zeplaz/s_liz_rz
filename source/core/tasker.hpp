

//que
#ifndef SLAZERZ_01_QUE_TEMPLATE_001_HPP
#define SLAZERZ_01_QUE_TEMPLATE_001_HPP

#include <functional>
//#include <unordered_map>
//#include <queue>

//#include <iostream>

//#include "utilityz/locks.hpp"

//3rd library 

#include <taskflow/taskflow.hpp>

/*
enum class Call_Tag : uint32_t {
PRICE_CALLS,
K_LINE_CALLS,
SEVER_TIME_CALLS
};

enum class Task_Tag : uint32_t
{
	BINANCE_TASK,
	RENDER_TASK,
	GUI_STATE_TASK,
	SYSTEM_STAGE
};

template<class T, class Tag>
class que
{	
	std::queue<T> the_q;
	Tag call_type;

};


template<class T, class Tag>
class f_list
{	
	std::forward_list the_list;
	Tag call_type;

};

//td::function<bool(Call_Tag)> price_call =[](){};


struct task
{
	int id;
	std::function<void()> f;
	void operator()() { f(); }
}

*/

namespace utli_task
{
	extern tf::Executor executor;
	extern tf::Taskflow taskflow;
	extern tf::Semaphore semaphore_Price_Map; 
};

class task_cmder
{

	public : 
//extern tf::Executor executor;

//extern 
  
  // define a critical region of 1 worker
//extern tf::Semaphore semaphore;

	private :

	public: 

		
};


	/*
	std::unordered_map<Task_Tag,que*> q_bank;
	std::unordered_map<Func_Tag,std::function> func_cache;
	std::unordered_map<Task_Tag,f_list*> fl_bank;

template<class T, class Tag>
void do_binace_tasks(std::function<bool(Call_Tag,que<T,Tag>)> do_calls_of)
{
	it = q_bank.find(Q_Tag::BINANCE_TASK);
  	if (it != q_bank.end())
	{
     if(!do_calls_of(it->second.call_type,it->second.the_q.front()))
     {
     	std::cerr <<"#####ERRRROT::q_cmder:::in do_biance_tasks inwell somthing\n";
     }
	}


}
void cycle()
	{
		
	
		for(auto it = q_bank.begin(); it = q_bank.end(); it++
		{
			if(!it->second.empty())
			{
				it->second.the_q.front();
			}

		} 
		
	}


bool run_calls(Call_Tag in_call_tag)
{
	if(in_call_tag ==Call_Tag::PRICE_CALLS)
	{

	}
}

class task_cmder
{};

*/	


#endif