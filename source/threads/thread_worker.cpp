///thread_worker.cpp
#include "thread_worker.hpp"

    thread_worker::thread_worker()
    {
        work_que.store(new std::queue<work_request>);
    }
    thread_worker::~thread_worker()
    {
        delete work_que.load();
    }

    void thread_worker::process_next()
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

    Key thread_worker::create_request(std::atomic<contaner_02*>& des_bank, exmpdata edat)
    {
        work_request wr(des_bank, edat);
        work_que.load()->push(std::move(wr));
        des_bank.load()->registar(edat.samkey);
        are_pending();
        return edat.samkey;
    }

    void thread_worker::shutdown()
    {
        fmt::print("shutdown single.. lol should THIS BE ATTOMIC I THINK SO!\n");
        shutdown_signa = true;
        cv.notify_all();
    }

    void thread_worker::operator()()
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
