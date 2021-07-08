






inline int get_next_id_with_t()
{	
	int temp = next_ppp_ID;
	next_ppp_ID++;
	return temp;
}

inline int get_next_ppp_ID()
{
	next_ppp_ID++;	
	return next_ppp_ID;
}

double& get_price_ppp(price_point_pair& p)  { return p.first; } 

clock_time_point& get_time_ppp(price_point_pair& p)  { return p.second; } 

double const& get_price_ppp(price_point_pair const& p)  { return p.first; } 

clock_time_point const& get_time_ppp(price_point_pair const& p)  { return p.second; } 

double get_double_time(auto& p) 
{
	return p.time_since_epoch().count();
}

 double get_double_time(auto&& p) 
{	
	#ifdef DEBUG_01
//	std::cerr <<  "#-->DEBUG::rvalue gdt::" << p.time_since_epoch().count() <<'\n';
	#endif 
	return p.time_since_epoch().count();
}


long get_long_time(auto& p) 
{
	return p.time_since_epoch().count();
}

long  get_long_time(auto&& p) 
{	
	
	return p.time_since_epoch().count();
}



price_point_pair make_ppp ( double p, clock_time_point ctp)
{
	return std::make_pair(p,ctp);
} 

auto high_now()
{
	return chrono::high_resolution_clock::now();
}
