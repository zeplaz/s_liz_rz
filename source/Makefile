

# g++ -I../3rd_party/binacpp/lib/libbinacpp/include -I../3rd_party/binacpp/lib/libwebsockets-2.4.0/include main.cpp price_point_cmder.cpp -L../3rd_party/binacpp/lib/libbinacpp/lib -L../3rd_party/binacpp/lib/libwebsockets-2.4.0/lib -lcurl -ljsoncpp  -lcrypto -lwebsockets -lbinacpp
CXX = g++
CXXFLAGS = -fconcepts-ts

LINKERFLAG = -lcurl -ljsoncpp -lcrypto -lwebsockets -lbinacpp 

libcurl_include = ../3rd_party/binacpp/lib/libcurl-7.56.0/include
jsoncpp_include = ../3rd_party/binacpp/lib/jsoncpp-1.8.3/include
libwebsockets_include = ../3rd_party/binacpp/lib/libwebsockets-2.4.0/include
libbinacpp_include = ../3rd_party/binacpp/lib/libbinacpp/include


libcurl_lib = ../3rd_party/binacpp/lib/libcurl-7.56.0/lib
jsoncpp_src = ../3rd_party/binacpp/lib/jsoncpp-1.8.3/src
libwebsockets_lib = ../3rd_party/binacpp/lib/libwebsockets-2.4.0/lib
libbinacpp_lib = ../3rd_party/binacpp/lib/libbinacpp/lib

#-I$(jsoncpp_include) 
#-I$(jsoncpp_include)
#-${jsoncpp_src}/jsoncpp.cpp
OBJS = main.o pp_cmder.o

sl_zerz: ${OBJS}
		${CXX} ${CPPFLAGS} -I$(libcurl_include) -I$(libwebsockets_include) -I$(libbinacpp_include) -L$(libcurl_lib) -L$(libwebsockets_lib) -L$(libbinacpp_lib) ${LINKERFLAGS} ${OBJS} ${LINKERFLAGS} -fPIC -o slz_zerz


main.o: main.cpp price_point_cmder.hpp 
	${CXX} ${CPPFLAGS} -I$(libcurl_include) -I$(libwebsockets_include) -I$(libbinacpp_include) -c main.cpp -ljsoncpp -fPIC - o main.o

pp_cmder.o:	price_point_cmder.hpp price_point_cmder.cpp 
	${CXX} ${CPPFLAGS} -I$(libcurl_include) -I$(libwebsockets_include) -I$(libbinacpp_include) -c price_point_cmder.cpp -ljsoncpp -fPIC -o pp_cmder.o

#-L$(libcurl_lib) -L$(libwebsockets_lib) -L$(libbinacpp_lib) ${LINKERFLAGS} 