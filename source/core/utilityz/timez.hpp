

#ifndef SLAZERZ_01_TIMEZ_001_HPP
#define SLAZERZ_01_TIMEZ_001_HPP
#include <chrono>

namespace chrono = std::chrono;
using namespace std::chrono_literals;
using clock_time_point = chrono::time_point<chrono::steady_clock>;


typedef std::pair<double,clock_time_point> price_point_pair;
typedef std::pair<double,long> price_time_l;

struct price_point_dtp
{
	double price;
	clock_time_point time_point;

};

struct price_point_dl
{
	double price;
	long time_point;

};

#endif