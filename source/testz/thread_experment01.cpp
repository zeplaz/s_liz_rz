//thread_experment01
/*
testing use case relablity racecodtions and profliing of three diffrent methods of cocurncy
*/

#include "../core/utilityz/errorhandler.hpp"
#include "../core/utilityz/timez.hpp"

#include <functional>
#include <memory>

#include <thread>
#include <atomic>
#include <condition_variable> // std::condition_variable
#include <mutex> 

#include <string>
#include <unordered_map>
#include <queue>     

#include "../../3rd_party/stdext/atomic_shard_ptr.hpp"


#if defined(__GNUC__)
#pragma GCC diagnostic ignored "-Wpragmas"                  // warning: unknown option after '#pragma GCC diagnostic' kind
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"      // warning: cast to pointer from integer of different size
#pragma GCC diagnostic ignored "-Wformat-security"          // warning: format string is not a string literal (potentially insecure)
#pragma GCC diagnostic ignored "-Wdouble-promotion"         // warning: implicit conversion from 'float' to 'double' when passing argument to function
#pragma GCC diagnostic ignored "-Wconversion"               // warning: conversion to 'xxxx' from 'xxxx' may alter its value
#pragma GCC diagnostic ignored "-Wmisleading-indentation"   // [__GNUC__ >= 6] warning: this 'if' clause does not guard this statement      // GCC 6.0+ only. See #883 on GitHub.
#endif

#include <utility>  // std::pair
#include <atomic>   // std::atomic
#include <utility>
#include <complex>
#include <tuple>





struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(std::string x) const {
    	uint64_t y=0; 
    	  for (size_t i = 0; i < x.length(); i++)
    {
                char c = x.at(i);
    	y =+ (uint64_t)c;
    }
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(y + FIXED_RANDOM);
    }
};


struct exmpdata 
{
	int somedata = 4; 
	double someotherdata = 45.3;
	std::string samkey = "this is data";
};


struct Atomic_Pointer
{
	std::atomic<std::shared_ptr<exmpdata>> data;
	Atomic_Pointer(std::shared_ptr<exmpdata> a = nullptr) :data(a){};

	Atomic_Pointer(Atomic_Pointer&& other) noexcept
	{
		data.store(std::move(other.data.load()));
	}

	std::shared_ptr<exmpdata> load()
	{
		return data.load();
	}

	void store(std::shared_ptr<exmpdata> val)
	{
		data.store(val);
	}


	Atomic_Pointer(const Atomic_Pointer& other)
	{	
		data.store(other.data.load());
	}
};


struct dat2
{
	double d;
	double d2; 
};
typedef std::string Key;
//typedef std::tuple<bool, std::atomic<std::shared_ptr<exmpdata>>> atomic_tuple; 

 using  AtomicPair = std::pair<Key,Atomic_Pointer>;

 using testpair = std::pair<int, dat2>;

struct contaner_01 : std::unordered_map<Key, std::shared_ptr<exmpdata>,custom_hash>
{

	void registar(Key inkey)
	{
		std::shared_ptr<exmpdata> ed(nullptr);
		this->insert(std::make_pair(inkey, ed));
	}

};

typedef std::unordered_map<Key, std::atomic<std::shared_ptr<dat2>>> atomic_map;


struct contaner_02: std::unordered_map<Key,Atomic_Pointer,custom_hash>
{
	void registar(Key inkey)
	{	

		 //(*((this->insert(make_pair(inkey,mapped_type()))).first)).second;
		(*this)[inkey].store(nullptr); 
		 fmt::print("\n********keys registar in map:: {}**********\n", inkey);
	}

	void update_data(Key k,  exmpdata ap)
	{
		//contaner_02::const_iterator got = this->find (k);
		fmt::print("\n\n*******at KEY::{}********\n\n", k);	 

		(*this)[k].store(std::make_shared<exmpdata>(ap)); 
	}

	int retreive(Atomic_Pointer& out_ptr, Key const& k)
	{

		contaner_02::const_iterator got = this->find (k);

		 if ( got == this->end() )
	   		{
				fmt::print("Quote::{} does not exist\n", k);
	  			return 2;
	   		}
	 
	  	Atomic_Pointer temap =	got->second; 
	  	if(temap.load() == nullptr)
	  	{
	  		fmt::print("Quote::{} is in request que and has not been retived, try again\n", k);
	  		return 3;
	  	}
	  	
	  	else
	  	{	out_ptr.store(temap.data.load()); 
	  		return 0; 
	  	}

		}

};


struct work_request
{	
	work_request(std::atomic<contaner_02*>& db, exmpdata d)
	{	
		edat = d;
		des_bank.store(db.load());
	}
	exmpdata edat; 
	std::atomic <contaner_02*> des_bank;


	work_request(work_request&& other)
	{
		edat = std::move(other.edat);
		des_bank.store(std::move(other.des_bank.load()));
	}
	work_request(work_request& other)
	{
		edat = other.edat;
		des_bank.store(other.des_bank.load());
	}
};

struct thread_worker
{

	std::condition_variable cv;
	std::mutex mtx;
	
	std::atomic<std::queue<work_request>*> work_que;

	std::atomic<bool> work_pending = false;

	bool shutdown_signa = false;

	thread_worker()
	{
		work_que.store(new std::queue<work_request>);
	}
	~thread_worker()
	{
		delete work_que.load();
	}

	void process_next()
	{
		unsigned int size = work_que.load()->size(); 
		fmt::print("quote_requester::process_next()size::{} \n", size);
		work_request* qr = &work_que.load()->front();
		work_que.load()->pop();
		
		//fmt::print("quote_requester:AFTER POP)size::{} \n", size;

			exmpdata d = qr->edat;

			d.someotherdata =+(double) (rand() % 10 + 1); 
			//fmt::print("loeading key::")
			qr->des_bank.load()->update_data(d.samkey,d);
	
	}

	Key create_request(std::atomic<contaner_02*>& des_bank, exmpdata edat)
	{
		work_request wr(des_bank, edat);
		work_que.load()->push(std::move(wr));
		des_bank.load()->registar(edat.samkey);
		are_pending();
		return edat.samkey;
	}

	void shutdown()
	{	
		fmt::print("shutdown single.. lol should THIS BE ATTOMIC I THINK SO!\n");
		shutdown_signa = true; 
		cv.notify_all();
	}

	void operator()()
	{
	while(!shutdown_signa)
		{
		fmt::print("while(!q_requester.shutdown_signa)\n");	
		std::unique_lock<std::mutex> lck(mtx);
		cv.wait(lck,[&]{
				fmt::print("q_requester.work_pending.load(){} ||||| q_requester.shutdown_signa{} \n",work_pending.load(), shutdown_signa);	
			
				bool val = work_pending.load() || shutdown_signa;
			return  val;});

		fmt::print("q_requester.cv.wait)\n");	

		while(are_pending())
		{	
			fmt::print("inside are pending...num pending:{}\n",work_que.load()->size());
			process_next();
		}

		fmt::print("threadwork)\n");	

		lck.unlock();
		
		}	
	}

	inline bool are_pending()
	{
		if(work_que.load()->size()!=0)
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
};

const std::string key1 = "key1";
const std::string key2 = "key2";
const std::string key3 = "key3";
const std::string key4 = "key4";


std::vector<std::string> gened_keys; 




int main(int argc, char** argv)
{

	auto start01 = chrono::high_resolution_clock::now();
	auto end01   = chrono::high_resolution_clock::now();
	
	auto start02 = chrono::high_resolution_clock::now();
	auto end02   = chrono::high_resolution_clock::now();

	auto start03 = chrono::high_resolution_clock::now();
	auto end03   = chrono::high_resolution_clock::now();
	
	chrono::duration<double> diff = end01-start01;
	chrono::duration<double> diff2 = end02-start02;
	chrono::duration<double> diff3 = end03-start03;


	 contaner_01 con1;
	 
	 contaner_02 con2; 

	 std::atomic<contaner_02*> atom_con2;
	 atom_con2.store(&con2); 

	 std::shared_ptr<contaner_01> con1_prt2(contaner_01);

	 std::atomic<std::shared_ptr<contaner_01>> atomic_container; 

	 atomic_container.store(std::shared_ptr<contaner_01>(new contaner_01));

	 thread_worker worker;


	 std::shared_ptr<contaner_01> con1_ptr = std::make_shared<contaner_01>(con1);

	 std::atomic< std::shared_ptr<contaner_01>> con1_ptr_atom;
	 con1_ptr_atom.store(std::make_shared<contaner_01>(con1)); 

	 std::vector<exmpdata> exampledata_vec; 
	 	 std::thread tworker1(std::ref(worker));

	 for(int i = 0 ; i <20; i++)
	 {
	 	gened_keys.push_back(key1+std::to_string(i));
	 	gened_keys.push_back(key2+std::to_string(i));
	 	gened_keys.push_back(key3+std::to_string(i));
	 	gened_keys.push_back(key4+std::to_string(i));
	 
	 	
	 }
	 for(size_t i =0; i< gened_keys.size(); i++)
	 {	
	 	exmpdata ed;
	 	ed.samkey = gened_keys.at(i);
	 	exampledata_vec.push_back(ed);
	 }

size_t g =0;
	 for(size_t i = 0; i < exampledata_vec.size(); i++)
	 {
	 		 worker.create_request(atom_con2, exampledata_vec.at(i));
	 	g++; 
	 }

	/* fmt::print("\n**********requests sent for half\n");
	 for(size_t i =0; i< con2.size(); i++)
	 {
	 	Atomic_Pointer aptemp; 
	 	//int code = con2.retreive(aptemp,gened_keys.at(i));
	 	int code = atom_con2.load()->retreive(aptemp,gened_keys.at(i));
	 	fmt::print("retrivealcode::{}\n", code);

	 	if( code ==0 )
	 	{
	 	std::shared_ptr<exmpdata>  exmp = aptemp.load();
	 	fmt::print("\n **************print key and some data {} , {}\n\n", exmp->samkey, exmp->someotherdata);
	 	}
	 }*/


	 /*fmt::print("\n**********rafter 1st lookup adding more\n");
	 for(g;g< exampledata_vec.size(); g++)
	 {
	 	worker.create_request(atom_con2, exampledata_vec.at(g));

	 }*/

/*

	  for(size_t i =0; i< con2.size()||i<gened_keys.size(); i++)
	 {
	 	Atomic_Pointer aptemp; 
	 	fmt::print("sizes..con2 {},gen {}, i {}\n", con2.size(), gened_keys.size(), i );
	 	//int code = con2.retreive(aptemp,gened_keys.at(i));
	 	int code = 5;//atom_con2.load()->retreive(aptemp,gened_keys.at(i));
	 	fmt::print("retrivealcode::{} at Key::{}\n", code,gened_keys.at(i));
	 	if( code ==0 )
	 	{
	 	std::shared_ptr<exmpdata>  exmp = aptemp.load();
	 	fmt::print("\n **************print key and some data {} , {}\n\n", exmp->samkey, exmp->someotherdata);
	 	}

	 }

	 for(int i =0; i<200; i++)
	 {
	 	printf("busssy\n");
	 }


	 atomic_map amap; 
	 dat2 da; 
	 amap[key1] = std::make_shared<dat2>(da);
	 */
 	 worker.shutdown();

	 tworker1.join();


return 0;
}
