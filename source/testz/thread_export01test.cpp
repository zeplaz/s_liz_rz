//thread_export01test.

//#include "../threads/atomic_pointer.hpp"
#include "../threads/atomic_unorderd_map.hpp"

#include "../yahoofinace/yah_req_threader.hpp"

#include <iostream>

#include <thread>
//thread_worker



int main( int argc, char** argv)

{
	parser_quote_yah pq;

	quote_bank qb;
	auto  s_qb = std::make_shared<quote_bank>(qb);
	//Atomic_Pointer<quote_bank>* ap_bank = new Atomic_Pointer<quote_bank>(qb);
	Atomic_Pointer<quote_bank> ap_bank(s_qb);

	thread_worker<quote_bank,quote_req_pak,quote_yah> yahoo_thead_worker(process_call_yahoo);

	std::thread tworker1(std::ref(yahoo_thead_worker));


	quote_req_pak test_req (&pq,"HUT",i1mo,g1d); 
	Key the_rquested_key = yahoo_thead_worker.create_request(&ap_bank ,test_req);

	fmt::print("what is the requested key::{}", the_rquested_key);

	for(int i =0; i<8000; i++)
	{
	 printf("busssy\n");

	}


	std::string val; 
	std::cin >> val;

	Atomic_Pointer<quote_yah> active_quote;
	int code =  s_qb->retreive(active_quote,the_rquested_key);
	fmt::print("\n stauscode::{} \n\n", code);

	fmt::print("\n size of map::{} \n\n", qb.size);
	
	if(code ==0)
	{
		std::shared_ptr<quote_yah> qyhut = active_quote.load();
		fmt::print("symbol::{}\n", qyhut->symbol);
		for(size_t i = 0; i< qyhut->num_spots(); i++)
		{
			fmt::print("thespotzbeat::{}",qyhut->spots.at(i).to_string());
		}
	}

		yahoo_thead_worker.shutdown();
	tworker1.join();


	return 0;

}
