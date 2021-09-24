#makefile test error code
CXX = g++
CPPFLAGS = -std=c++20 -pg -fconcepts-ts  -Wall -pedantic -g -O0
LINKERFLAG =  -lcurl -lfmt -lpthread -lGLEW -lglfw -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl 
LIBSTD06   =  /usr/lib64/libstdc++.so.6

THRID_PARTY_INCLUDE = "../3rd_party" 
YAHOOF_UTILS_INCLUDE = "./3rd_party/yahooF_utils"

OBJS = t_yahooF_curl.o curl_handler_yf.o parser_yah.o quote_spot_yah.o quote_requester.o
FMT_INCLUDE = /usr/local/include/fmt


yahooF_test: ${OBJS}
	${CXX} ${CPPFLAGS} ${OBJS} -L$(LIBSTD06) ${LINKERFLAG}  -o yahooF_test

t_yahooF_curl.o: testz/t_yahooF_curl.cpp
	${CXX} ${CPPFLAGS} -c -g testz/t_yahooF_curl.cpp

curl_handler_yf.o:yahoofinace/yf_curl.hpp yahoofinace/curl_handler_yf.cpp  
	${CXX} ${CPPFLAGS} -c -g  yahoofinace/curl_handler_yf.cpp  

parser_yah.o:yahoofinace/yf_curl.hpp yahoofinace/parser_yah.cpp  
	${CXX} ${CPPFLAGS} -c -g  yahoofinace/parser_yah.cpp  

quote_spot_yah.o: yahoofinace/yf_curl.hpp yahoofinace/quote_spot_yah.cpp  
	${CXX} ${CPPFLAGS} -c -g yahoofinace/quote_spot_yah.cpp  

quote_requester.o: yahoofinace/yf_curl.hpp yahoofinace/quote_requester.hpp yahoofinace/quote_requester.cpp
	${CXX} ${CPPFLAGS} -c -g yahoofinace/quote_requester.cpp

.PHONY : clean
clean :
	-rm yahooF_test $(OBJS)