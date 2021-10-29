#ifndef SLAZERZ_01_ATOMIC_POINTER_001_HPP
#define SLAZERZ_01_ATOMIC_POINTER_001_HPP

#include <memory>
#include <atomic>   // std::atomic

#include "../../3rd_party/stdext/atomic_shard_ptr.hpp"

template<typename T>
struct Atomic_Pointer
{

private : 
	std::atomic<std::shared_ptr<T>> data;
	//Atomic_Pointer(T a) :data(std::make_shared<T>(a)){};
public: 
	Atomic_Pointer(std::shared_ptr<T> a = nullptr) :data(a){};
	
	//
	Atomic_Pointer(T& a) :data(std::make_shared<T>(a)){};

	Atomic_Pointer(const Atomic_Pointer& other)
	{	
		data.store(other.load());
	}
	
	Atomic_Pointer(Atomic_Pointer&& other) noexcept
	{
		data.store(std::move(other.load()));
	}

	std::shared_ptr<T> load() const
	{
		return data.load();
	}

	void store(std::shared_ptr<T> val)
	{
		data.store(val);
	}


};

#endif

