
#ifndef SLAZERZ_01_ATOMIC_UNORDERD_MAP_001_HPP
#define SLAZERZ_01_ATOMIC_UNORDERD_MAP_001_HPP

#include "custom_hash.hpp"
#include "atomic_pointer.hpp"


#include "../core/utilityz/errorhandler.hpp"


template<class KEY,typename T>
struct atomic_unorderd_map: std::unordered_map<KEY,Atomic_Pointer<T>,custom_hash>
{	
	size_t size =0; 
	//typename KEY_TYPE 
	void registar(KEY const& inkey)
	{
	 size++; 	
	(*this)[inkey].store(nullptr); 	
	}

	void update_data(KEY const& k, T data)
	{
	(*this)[k].store(std::make_shared<T>(data)); 
	}

	void update_data(KEY const& k, std::shared_ptr<T> data)
	{
	(*this)[k].store(data); 
	}

	int retreive(Atomic_Pointer<T>& out_ptr, KEY const& k) 
	{
		typename atomic_unorderd_map::const_iterator got = this->find(k);

		if(got == this->end())
		{
			fmt::print("Quote::{} does not exist\n", k);

			return NOTFOUND; 
		}
		
		else
		{
			Atomic_Pointer temap =	got->second; 
		  	if(temap.load() == nullptr)
		  	{
		  		fmt::print("Quote::{} is in request que and has not been retived, try again\n", k);
		  		return NOT_PROCESSED_IN_QUE;
		  	}
	  	
		  	else
		  	{	
		  		out_ptr.store(temap.load()); 
		  		return 0; 
		  	}

		}
	}

};

#endif