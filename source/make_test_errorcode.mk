#makefile test error code
CXX = g++
CPPFLAGS = -std=c++20 -pg -fconcepts-ts  -Wall -pedantic

LINKERFLAG =  -lfmt -lpthread -lGLEW -lglfw -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl 
LIBSTD06   =  /usr/lib64/libstdc++.so.6

THRID_PARTY_INCLUDE = "../3rd_party" 

#FMT_INCLUDE= "../3rd_party/fmt/include"  
OBJS = ut_renderer_0_1.o
FMT_INCLUDE = /usr/local/include/fmt
error_test: ${OBJS}
	${CXX} ${CPPFLAGS} ${OBJS} -L$(LIBSTD06) ${LINKERFLAG}  -o error_test

ut_renderer_0_1.o: testz/ut_renderer_0_1.cpp
	${CXX} ${CPPFLAGS} -c -g testz/ut_renderer_0_1.cpp
.PHONY : clean
clean :
	-rm error_test $(OBJS)