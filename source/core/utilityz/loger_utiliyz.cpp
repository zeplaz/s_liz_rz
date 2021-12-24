



#include "loger_utlityz.hpp"

#include "enumz_et_defultz.hpp"
#include "utilityz.hpp"


std::atomic<logger> logger::instance; 
std::mutex logger::logger_mutex; 


    MySingleton* sin= instance.load(std::memory_order_acquire);
    if ( !sin ){
      std::lock_guard<std::mutex> myLock(myMutex);
      sin= instance.load(std::memory_order_relaxed);

logger* logger::get_instance()
{
	
	static logger* sin = instance.load(std::memory_order_acquire);

		if(!sin)
		{	
			std::lock_guard<std::mutex> myLock(logger_mutex);
			sin= instance.load(std::memory_order_relaxed);

			if(!sin)
			{
				sin = new logger;
				instance.store(sin,std::memory_order_acquire);		
			}
		}
	}

	return sin; 

}




