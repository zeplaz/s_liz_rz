#makefile test error code
CXX = g++
CPPFLAGS = -std=c++20 -pg -fconcepts-ts  -Wall -pedantic

LINKERFLAG =  -lcurl -lfmt -lpthread -lGLEW -lglfw -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl 
LIBSTD06   =  /usr/lib64/libstdc++.so.6

THRID_PARTY_INCLUDE = "../3rd_party" 
YAHOOF_UTILS_INCLUDE = "./3rd_party/yahooF_utils"

OBJS = t_yahooF_curl.o #time_utils.o
FMT_INCLUDE = /usr/local/include/fmt


yahooF_test: ${OBJS}
	${CXX} ${CPPFLAGS} ${OBJS} -L$(LIBSTD06) ${LINKERFLAG}  -o yahooF_test

t_yahooF_curl.o: testz/t_yahooF_curl.cpp
	${CXX} ${CPPFLAGS} -c -g testz/t_yahooF_curl.cpp

#time_utils.o: ../3rd_party/yahooF_utils/time_utils.cpp ../3rd_party/yahooF_utils/time_utils.hpp
#	${CXX} ${CPPFLAGS} -I$(THRID_PARTY_INCLUDE) -I$(YAHOOF_UTILS_INCLUDE) -c -g ../3rd_party/yahooF_utils/time_utils.cpp 



.PHONY : clean
clean :
	-rm yahooF_test $(OBJS)