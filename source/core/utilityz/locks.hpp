//locks.hpp

#ifndef SLAZERZ_01_MUTEX_LCOKZ_001_HPP
#define SLAZERZ_01_MUTEX_LOCKZ_001_HPP

#include <mutex>
//#include <taskflow/taskflow.hpp>
#include <semaphore>
/*
LOCKS MUST BE Extern and inilaized in a cpp. to provent mutli def appearing. change namespace to thread_utlity? or like 
cocurrnyzctlz"? idk..
*/
namespace utility
{
extern std::mutex lock_price_Map;	
extern std::counting_semaphore<1> lock_price_semaphore;

}





#endif


