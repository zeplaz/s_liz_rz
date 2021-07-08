


#include "price_point_cmder.hpp"

#include <iostream>
#include <string>
#include <typeinfo>

#include <future> 

typedef std::pair<double,long> pairtype;

constexpr long MAXLOOP = 300000;

double a_aprice; 



void lop_1(double testva, std::array<price_ltime,MAXLOOP>* pt_array){

	int points_1=0;
	int points_2=0;
	int points_3=0;
	int points_4=0;

	double courrent_low; 
	int curr_point =0;

		for(int k = 0; k<100; k++)
	{
			std::cout << "k::" << k <<'\n';

	auto start_01 = high_now();
	for(long i = 0; i < MAXLOOP; i++)
	{	
		//pairtype  temp = );
		pt_array->at(i) = price_ltime(i,std::make_pair(testva,chrono::high_resolution_clock::now().time_since_epoch().count()));
	}

	for(long i = 0; i < MAXLOOP; i++)
	{	
		//pairtype  temp = );
		pt_array->at(i) = price_ltime(i,std::make_pair(testva,chrono::high_resolution_clock::now().time_since_epoch().count()));
	}
	auto end_01 = high_now();



	auto start_02 = high_now();

	for(int i = 0; i < MAXLOOP; i++)
	{	

		//pairtype temp = 
		pt_array->at(i) = make_plt_1(testva,high_now());
	}
	for(int i = 0; i < MAXLOOP; i++)
	{	

		//pairtype temp = 
		pt_array->at(i) = make_plt_1(testva,high_now());
	}
	auto end_02 = high_now();



	auto start_03 = high_now();

	for(int i = 0; i < MAXLOOP; i++)
	{
		pt_array->at(i) =make_plt_2(testva,high_now());
	}

	for(int i = 0; i < MAXLOOP; i++)
	{
		pt_array->at(i) =make_plt_2(testva,high_now());
	}
	auto end_03 = high_now();


	auto start_04 = high_now();

	for(int i = 0; i < MAXLOOP; i++)
	{
		pt_array->at(i) = make_plt_2(testva,chrono::high_resolution_clock::now());
	}

	for(int i = 0; i < MAXLOOP; i++)
	{
		pt_array->at(i) = make_plt_2(testva,chrono::high_resolution_clock::now());
	}
	auto end_04 = high_now();


	chrono::duration<double> diff = end_01-start_01;
	//std::cout << std::setw(12);

	//
	//curr_point = 1;

	std::cout << "time_dif1::" << diff.count() << '\n';

	diff = end_02-start_02;
	std::cout << "time_dif2::" << diff.count() << '\n';
	courrent_low = diff.count();
	curr_point =2;
	/*if(diff.count() < courrent_low)
	{
		courrent_low = diff.count();
		
	}*/

	diff = end_03-start_03;
	std::cout << "time_dif3::" << diff.count() << '\n';
if(diff.count() < courrent_low)
	{
		courrent_low = diff.count();
		curr_point =3;
	}

	diff = end_04-start_04;
	std::cout << "time_dif4::" << diff.count() << '\n'; 

	if(diff.count() < courrent_low)
	{
		courrent_low = diff.count();
		curr_point =4;
	}

	switch(curr_point)
	{
		case 1 :
		{
			points_1 +=1;
			break;
		}

				case 2 :
		{
			points_2 +=1;
			break;
		}

				case 3 :
		{
			points_3 +=1;
			break;
		}

				case 4 :
		{
			points_4 +=1;
			break;
		}
	}



}
}

int main(int argc, char** argv)
{
	
	double time_01 = get_double_time(high_now()); 
	price_point pp_1;
	pairtype pt_01;

	//std::array<price_point,MAXLOOP> ppp_array;
	std::array<price_ltime,MAXLOOP> pt_array;

	pp_1.data = make_ppp(2948.22, high_now());
	double testva = get_price_ppp(pp_1.data);


	int points_1=0;
	int points_2=0;
	int points_3=0;
	int points_4=0;

	double courrent_low; 
	int curr_point =0;

	auto start_asy = high_now();
	 auto handle = std::async(std::launch::async,
                             lop_1, testva,&pt_array);
	//std::future<void> result(std::async(lop_1,testva,pt_array));
	auto end_asy = high_now();
	chrono::duration<double> diffasy = end_asy-start_asy;



	auto start_n = high_now();/*
		for(int k = 0; k<100; k++)
	{
			std::cout << "k::" << k <<'\n';

	auto start_01 = high_now();
	for(long i = 0; i < MAXLOOP; i++)
	{	
		//pairtype  temp = );
		pt_array.at(i) = price_ltime(i,std::make_pair(testva,chrono::high_resolution_clock::now().time_since_epoch().count()));
	}

	for(long i = 0; i < MAXLOOP; i++)
	{	
		//pairtype  temp = );
		pt_array.at(i) = price_ltime(i,std::make_pair(testva,chrono::high_resolution_clock::now().time_since_epoch().count()));
	}
	auto end_01 = high_now();



	auto start_02 = high_now();

	for(int i = 0; i < MAXLOOP; i++)
	{	

		//pairtype temp = 
		pt_array.at(i) = make_plt_1(testva,high_now());
	}
	for(int i = 0; i < MAXLOOP; i++)
	{	

		//pairtype temp = 
		pt_array.at(i) = make_plt_1(testva,high_now());
	}
	auto end_02 = high_now();



	auto start_03 = high_now();

	for(int i = 0; i < MAXLOOP; i++)
	{
		pt_array.at(i) =make_plt_2(testva,high_now());
	}

	for(int i = 0; i < MAXLOOP; i++)
	{
		pt_array.at(i) =make_plt_2(testva,high_now());
	}
	auto end_03 = high_now();


	auto start_04 = high_now();

	for(int i = 0; i < MAXLOOP; i++)
	{
		pt_array.at(i) = make_plt_2(testva,chrono::high_resolution_clock::now());
	}

	for(int i = 0; i < MAXLOOP; i++)
	{
		pt_array.at(i) = make_plt_2(testva,chrono::high_resolution_clock::now());
	}
	auto end_04 = high_now();


	chrono::duration<double> diff = end_01-start_01;
	//std::cout << std::setw(12);

	//
	//curr_point = 1;

	std::cout << "time_dif1::" << diff.count() << '\n';

	diff = end_02-start_02;
	std::cout << "time_dif2::" << diff.count() << '\n';
	courrent_low = diff.count();
	curr_point =2;
	/*if(diff.count() < courrent_low)
	{
		courrent_low = diff.count();
		
	}

	diff = end_03-start_03;
	std::cout << "time_dif3::" << diff.count() << '\n';
if(diff.count() < courrent_low)
	{
		courrent_low = diff.count();
		curr_point =3;
	}

	diff = end_04-start_04;
	std::cout << "time_dif4::" << diff.count() << '\n'; 

	if(diff.count() < courrent_low)
	{
		courrent_low = diff.count();
		curr_point =4;
	}

	switch(curr_point)
	{
		case 1 :
		{
			points_1 +=1;
			break;
		}

				case 2 :
		{
			points_2 +=1;
			break;
		}

				case 3 :
		{
			points_3 +=1;
			break;
		}

				case 4 :
		{
			points_4 +=1;
			break;
		}
	}



}*/
	auto end_n = high_now();
	chrono::duration<double> diffn = end_n-start_n;




		std::cout << "\n****************************************\n"
		<< "#DISABPLED::points_1::" << points_1 << '\n' 
		<< "points_2::" << points_2 << '\n' 
		<< "points_3::" << points_3 << '\n' 
		<< "points_4::" << points_4 << '\n'; 
	 std::cout << "testval::" << testva << "at::" << get_long_time(get_time_ppp(pp_1.data)) <<'\n'; 
	 
	 auto time_type = get_time_ppp(pp_1.data).time_since_epoch().count(); 

				
	 std::string s = typeid(time_type).name();

	 std::cout <<"so what tipe is time...:" << s << '\n';
	// std::cout <<"so what size is mypair...:" << sizeof(ppp_array) << '\n';	
     std::cout <<"so what sie is a long and double..:" << sizeof(pt_array) << '\n';



     std::cout << "\n time diffrences of asyna and normal.\n"
     << "asycn::" << diffasy.count() << "\n NOrmal run::" << diffn.count() << '\n'; 


	return 0;
}