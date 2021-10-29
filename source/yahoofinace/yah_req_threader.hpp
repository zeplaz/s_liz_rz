
#ifndef SLAZERZ_01_YAH_REQ_THREADZ_001_HPP
#define SLAZERZ_01_YAH_REQ_THREADZ_001_HPP

#include "../threads/thread_worker.hpp"

#include "parser_yah.hpp"
#include "quote_bank.hpp"
#include "quote_spot_yah.hpp"

quote_yah process_call_yahoo(quote_req_pak const& qr)
{
  quote_yah tempq = qr.pq->get_quote(qr.symbol, qr.interval, qr.granulity);
  return tempq;
}


#endif
  //  work_request<quote_bank> yahoo_request;
