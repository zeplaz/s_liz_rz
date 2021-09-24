#makefile test error code
CXX = g++
CPPFLAGS = -std=c++20 -pg -fconcepts-ts  -Wall -pedantic 
LINKERFLAG =  -lcurl -lfmt -lpthread -lGLEW -lglfw -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl 
LIBSTD06   =  /usr/lib64/libstdc++.so.6

THRID_PARTY_INCLUDE = "../3rd_party" 


OBJS = thread_experment01.o
FMT_INCLUDE = /usr/local/include/fmt


atomthreadtest: ${OBJS}
	${CXX} ${CPPFLAGS} ${OBJS} -L$(LIBSTD06) ${LINKERFLAG}  -o atomthreadtest

thread_experment01.o: testz/thread_experment01.cpp
	${CXX} ${CPPFLAGS} -c -g testz/thread_experment01.cpp


.PHONY : clean
clean :
	-rm atomthreadtest $(OBJS)