



build_dir=../lib/libbinacpp/lib
objects=$(build_dir)/binacpp_utils.o $(build_dir)/binacpp_logger.o $(build_dir)/binacpp.o  $(build_dir)/binacpp_websocket.o

build_include=../lib/libbinacpp/include


$(build_dir)/libbinacpp.so: $(objects)
	g++ $(objects) \
	-shared \
	-lcurl -lcrypto -lwebsockets -ljsoncpp -fPIC -o $@

	# Make a new copy of the header too
	cp *.h  $(build_include)


$(build_dir)/binacpp.o: binacpp.cpp binacpp.h 
	g++ -c binacpp.cpp  -fPIC   -o $(build_dir)/binacpp.o 

$(build_dir)/binacpp_websocket.o: binacpp_websocket.cpp binacpp_websocket.h 
	g++ -c binacpp_websocket.cpp  -fPIC -o $(build_dir)/binacpp_websocket.o


$(build_dir)/binacpp_logger.o: binacpp_logger.cpp binacpp_logger.h 
	g++ -c binacpp_logger.cpp  -fPIC   -o $(build_dir)/binacpp_logger.o 



$(build_dir)/binacpp_utils.o: binacpp_utils.cpp binacpp_utils.h 
	g++ -c binacpp_utils.cpp -fPIC   -o $(build_dir)/binacpp_utils.o 


clean:
	rm $(build_dir)/*.o
	rm $(build_dir)/*.so






