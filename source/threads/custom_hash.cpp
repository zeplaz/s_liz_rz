//th

    #include "custom_hash.hpp"

	#include <chrono>

	
    size_t custom_hash::operator()(std::string x) const {
    	uint64_t y=0; 
    	  for (size_t i = 0; i < x.length(); i++)
    {
                char c = x.at(i);
    	y =+ (uint64_t)c;
    }
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(y + FIXED_RANDOM);
    }