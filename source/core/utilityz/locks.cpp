///cpp

#include "locks.hpp"
std::mutex utility::lock_price_Map;

std::counting_semaphore<1> utility::lock_price_semaphore(1);