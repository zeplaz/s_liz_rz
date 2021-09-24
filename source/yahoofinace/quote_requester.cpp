#include "quote_requester.hpp"





Key quote_bank::make_key(quote_req_pak const& qrpak)
	{	
		std::string key = symb + std::to_string(interval)+ std::to_string(granulity);
		key_bank.push_back(key);
		return key;
	}

	Key quote_bank::get_last_key()
	{
		if(!key_bank.empty())
		{
			return key_bank.back();
		}
	}

	 key quote_bank::registar(quote_req_pak const& qrpak)
	{
		key k = make_key(prpak);
		std::shared_ptr<quote_yah> qy(nullptr);

		this->insert(std::make_pair(k,qy));
	}
	

	Quote_Status quote_bank::retreive(Quote_ptr& out_quote , key const& k)
{
	quote_bank::const_iterator got = this.find (k);

	  if ( got == this.end() )
   		{
   			fmt::print("Quote::{} does not exist\n", key);
  		return INQUE;
   		}
   	// std::cout << "not found";
  else
  {
  	if(got->second == nullptr)
  	{
  		fmt::print("Quote::{} is in request que and has not been retived, try again\n", key);
  		return NOTFOUND;
  	}
  	else
  	{	
  		out_quote = got->second; 
  		return 0; 
  	}

	}

  quote_request::quote_request(std::shared_ptr<quote_bank> dest, std::string sym, int i, int g)
	{
		dest_bank_ptr.store(dest);
		symbol = sym;
		interval = i;
		granulity = g;
	}

void thread_quote_worker::operator()()
{		
		fmt::print("THREAD QUOTER OPERATOR()shutdown_signa::{}\n",q_requester.shutdown_signa);
		while(!q_requester.shutdown_signa)
		{
		fmt::print("while(!q_requester.shutdown_signa)\n");	
		std::unique_lock<std::mutex> lck(q_requester.mtx);
		q_requester.cv.wait(lck,[&]{
				fmt::print("q_requester.work_pending.load(){} ||||| q_requester.shutdown_signa{} \n",q_requester.work_pending.load(), q_requester.shutdown_signa);	
			
				bool val = q_requester.work_pending.load() || q_requester.shutdown_signa;
			return  val;});

		fmt::print("q_requester.cv.wait)\n");	

		while(q_requester.are_pending())
		{	
			fmt::print("inside are pending...num pending:{}\n",q_requester.num_pending());
			q_requester.process_next();
		}
		lck.unlock();
		
		}	
}

void quote_requester::process_next()
{
	fmt::print("quote_requester::process_next() \n");
	quote_request* qr = &que_q_req.front();
	que_q_req.pop();

	quote_yah tempq = pq.get_quote(qr->symbol, qr->interval, qr->granulity);

	

	std::shared_ptr<quote_bank> qb_ptr = qr->dest_bank_ptr.load();
	fmt::print(" qr->dest_bank_ptr.load() \n");


	//qb_ptr->push_back(tempq);
	std::string key = qr->symbol + std::to_string(qr->interval)+ std::to_string(qr->granulity);
	qb_ptr->insert(std::make_pair(key,tempq));
}

Q_Key quote_requester::create_request(std::shared_ptr<quote_bank> dest_bank, quote_req_pak const& qr_pak)
{	
	
	quote_request qr(dest_bank, qr_pak); 
	que_q_req.push(std::move(qr)); 
	are_pending();
	return dest_bank->registar(qr_pak);;  
 	
}

