

#ifndef SLAZERZ_01_QUOTE_BANK_001_HPP
#define SLAZERZ_01_QUOTE_BANK_001_HPP

#include "../threads/atomic_unorderd_map.hpp"
#include "quote_spot_yah.hpp"
#include "yf_labels_lib.hpp"

typedef int Quote_Status;


enum Q_stat
{
	FOUND,
	INQUE,
	ERROR
	//NOTFOUND///a;ready defined make this class enum?
};

struct quote_bank : public atomic_unorderd_map<Q_Key,quote_yah>
{

	protected:
	std::vector<Q_Key> key_bank;

	public:
	Q_Key get_last_key();
	
	Q_Key make_key(quote_req_pak const& qrpak);

	quote_bank& operator = (const quote_bank& other) = delete;

};


#endif
