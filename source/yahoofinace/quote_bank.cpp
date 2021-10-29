
#include "quote_bank.hpp"


Q_Key quote_bank::make_key(quote_req_pak const& qrpak)
	{
		std::string key = qrpak.symbol + std::to_string(qrpak.interval)+ std::to_string(qrpak.granulity);
		key_bank.push_back(key);
		return key;
	}

Q_Key quote_bank::get_last_key()
	{
		if(!key_bank.empty())
		{
			return key_bank.back();
		}

		std::string keynotfound = "\0";
		return keynotfound;
	}
