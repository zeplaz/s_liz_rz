#makefile test error code
CXX = g++
CPPFLAGS = -std=c++20 -pg -fconcepts-ts  -Wall -pedantic 
LINKERFLAG =  -lcurl -lfmt -lpthread -lGLEW -lglfw -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl 
LIBSTD06   =  /usr/lib64/libstdc++.so.6

THRID_PARTY_INCLUDE = "../3rd_party" 


OBJS = thread_export01test.o custom_hash.o curl_handler_yf.o parser_yah.o quote_bank.o quote_spot_yah.o
FMT_INCLUDE = /usr/local/include/fmt


atomthreadtest: ${OBJS}
	${CXX} ${CPPFLAGS} ${OBJS} -L$(LIBSTD06) ${LINKERFLAG}  -o atomthreadtest

thread_export01test.o: testz/thread_export01test.cpp yahoofinace/yah_req_threader.hpp
	${CXX} ${CPPFLAGS} -c -g testz/thread_export01test.cpp

custom_hash.o: threads/custom_hash.cpp threads/custom_hash.hpp
	${CXX} ${CPPFLAGS} -c -g threads/custom_hash.cpp

curl_handler_yf.o: 	yahoofinace/curl_handler_yf.cpp yahoofinace/curl_handler_yf.hpp
	${CXX} ${CPPFLAGS} -c -g yahoofinace/curl_handler_yf.cpp

parser_yah.o: yahoofinace/parser_yah.cpp yahoofinace/parser_yah.hpp yahoofinace/yf_labels_lib.hpp
	${CXX} ${CPPFLAGS} -c -g yahoofinace/parser_yah.cpp

quote_bank.o: yahoofinace/quote_bank.cpp yahoofinace/quote_bank.hpp 
	${CXX} ${CPPFLAGS} -c -g yahoofinace/quote_bank.cpp

quote_spot_yah.o: yahoofinace/quote_spot_yah.cpp yahoofinace/quote_spot_yah.hpp
	${CXX} ${CPPFLAGS} -c -g yahoofinace/quote_spot_yah.cpp

.PHONY : clean_thread
clean_thread:
	-rm thread_export01test.o custom_hash.o

.PHONY : clean_yah
clean_yah:
	-rm quote_spot_yah.o quote_bank.o	

.PHONY : clean_parse
clean_parse:
	-rm parser_yah.o	

.PHONY : clean
clean :
	-rm atomthreadtest $(OBJS)

















	