#ifndef SLAZERZ_01_THREAD_WORKER_001_HPP
#define SLAZERZ_01_TJREAD_WORKER_001_HPP


#include <queue>
#include <functional>
#include <utility>

#include "atomic_pointer.hpp"


#include "../core/utilityz/errorhandler.hpp"


#include <string>
typedef std::string Key;

/*
there needs to be some test of TCONTANER to make sure its a map,... cuz otherwise ohno!
*/
template<typename TCONTANER, class PAK_TYPE, class KEY_TYPE = std::string>
struct work_request
{

    Atomic_Pointer<TCONTANER> des_bank;
    KEY_TYPE work_key;
    PAK_TYPE request_pak;

    work_request(Atomic_Pointer<TCONTANER>& db, KEY_TYPE const& k, PAK_TYPE const& pak)
    {
        fmt::print("CONSTUCTOR Atomic_Pointer<TCONTANER>& \n");
        
        work_key = k;
        request_pak = pak;
        des_bank.store(db.load());

    }
    work_request(TCONTANER& db, KEY_TYPE const& k, PAK_TYPE const& pak)
    {
        fmt::print("CONSTUCTOR TCONTANER& \n");
        
        work_key = k;
        request_pak = pak;
        des_bank.store(db);

    }
    //work_request(TCONTANER& db, KEY_TYPE k ) : des_bank(db), work_key(k){};

    work_request(work_request&& other)
    {
        work_key = std::move(other.work_key);
        request_pak = std::move(other.request_pak);
        des_bank.store(std::move(other.des_bank.load()));
    }
    work_request(work_request& other)
    {
        work_key = other.work_key;
        request_pak = other.request_pak;
        des_bank.store(other->des_bank.load());
    }
};

////need to work out the process function this is abit confused..
template<typename TCONTANER, class  PAK_TYPE, class RET>
struct thread_worker
{
    std::condition_variable cv;
    std::mutex mtx;

    std::atomic<std::queue<work_request<TCONTANER,PAK_TYPE>>*> work_que;

    std::atomic<bool> work_pending = false;

    std::atomic <bool> shutdown_signa = false;

    std::function<RET(PAK_TYPE)> FUNC_PROCESS;

    thread_worker() = delete;

    thread_worker(std::function<RET(PAK_TYPE)> in_fun)
    {
        work_que.store(new std::queue<work_request<TCONTANER,PAK_TYPE>>);
        FUNC_PROCESS = in_fun;
    }
    ~thread_worker()
    {
        delete work_que.load();
    }

    inline bool are_pending()
    {
        if(work_que.load()->size()!=0)
        {
           #ifdef DEBUG_01
           fmt::print("cv.notify_all();\n");
           #endif

            work_pending.store(true);
            cv.notify_all();
            return true;
        }
        else
        {
            #ifdef DEBUG_01
            fmt::print("work_pending.store(false);\n");
            #endif

            work_pending.store(false);
            return false;
        }
    }


//theres something off here...
    void process_next()
    {
        unsigned int size = work_que.load()->size();
        fmt::print("quote_requester::process_next()size::{} \n", size);


        work_request<TCONTANER,PAK_TYPE>* qr = &work_que.load()->front();
        work_que.load()->pop();

//////////////NEED SOME ALGURTHM HERE????? ///
      RET d  =  FUNC_PROCESS(qr->request_pak);
//////////////////////////////////////////////

      qr->des_bank.load()->update_data(qr->work_key,d);

    }

    Key create_request(Atomic_Pointer<TCONTANER>* des_bank, PAK_TYPE pak)
    {

        Key k = des_bank->load()->make_key(pak);
        des_bank->load()->registar(k);
        work_request<TCONTANER,PAK_TYPE> wr(*des_bank,k,pak);
        
        work_que.load()->push(std::move(wr));
        are_pending();
        return k;
    }

    void shutdown()
    {
        fmt::print("shutdown single.. lol should THIS BE ATTOMIC I THINK SO!\n");
        shutdown_signa.store(true);
        cv.notify_all();
    }

    void operator()()
    {
    while(!shutdown_signa.load())
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


};

    #endif
