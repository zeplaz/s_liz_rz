fmt.o: ../3rd_party/fmt/src/fmt.cc
	${CXX} ${CPPFLAGS} -I$(FMT_INCLUDE) -c -g ../3rd_party/fmt/src/fmt.cc

format.o: ../3rd_party/fmt/src/format.cc
	${CXX} ${CPPFLAGS} -I$(FMT_INCLUDE) -c -g ../3rd_party/fmt/src/format.cc

os.o: ../3rd_party/fmt/src/os.cc
	${CXX} ${CPPFLAGS} -I$(FMT_INCLUDE) -c -g ../3rd_party/fmt/src/os.cc