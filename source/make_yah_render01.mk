#makefile test error code
CXX = g++
CPPFLAGS = -std=c++20 -pg -fconcepts-ts  -Wall -pedantic 
LINKERFLAG =  -lcurl -lfmt -lpthread -lGLEW -lglfw -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl 
LIBSTD06   =  /usr/lib64/libstdc++.so.6

THRID_PARTY_INCLUDE ="../3rd_party" 
IMGUI_INC           ="../3rd_party/imgui"
IMGUI_BACKENDS_INC  ="../3rd_party/imgui/backends"

OBJS = engine.o glfw_windowBuilder.o gui_yahoo_combo.o custom_hash.o curl_handler_yf.o parser_yah.o quote_bank.o quote_spot_yah.o opengl_utility.o im_gui_modifed_backends.o imgui.o  imgui_draw.o imgui_tables.o imgui_widgets.o imgui_impl_opengl3.o 
FMT_INCLUDE = /usr/local/include/fmt


atomthreadtest: ${OBJS}
	${CXX} ${CPPFLAGS} ${OBJS} -L$(LIBSTD06) ${LINKERFLAG}  -o atomthreadtest

#main
gui_yahoo_combo.o: testz/gui_yahoo_combo.cpp yahoofinace/yah_req_threader.hpp
	${CXX} ${CPPFLAGS} -c -g testz/gui_yahoo_combo.cpp


#threads
custom_hash.o: threads/custom_hash.cpp threads/custom_hash.hpp
	${CXX} ${CPPFLAGS} -c -g threads/custom_hash.cpp

#yahoo finace
curl_handler_yf.o: 	yahoofinace/curl_handler_yf.cpp yahoofinace/curl_handler_yf.hpp
	${CXX} ${CPPFLAGS} -c -g yahoofinace/curl_handler_yf.cpp

parser_yah.o: yahoofinace/parser_yah.cpp yahoofinace/parser_yah.hpp yahoofinace/yf_labels_lib.hpp
	${CXX} ${CPPFLAGS} -c -g yahoofinace/parser_yah.cpp

quote_bank.o: yahoofinace/quote_bank.cpp yahoofinace/quote_bank.hpp 
	${CXX} ${CPPFLAGS} -c -g yahoofinace/quote_bank.cpp

quote_spot_yah.o: yahoofinace/quote_spot_yah.cpp yahoofinace/quote_spot_yah.hpp
	${CXX} ${CPPFLAGS} -c -g yahoofinace/quote_spot_yah.cpp

#engine
engine.o: core/engine.cpp core/engine.hpp
	${CXX} ${CPPFLAGS} -c -g core/engine.cpp

# render 
opengl_utility.o: core/opengl_utility.cpp core/opengl_utility.hpp
	${CXX} ${CPPFLAGS} -c -g core/opengl_utility.cpp

glfw_windowBuilder.o: core/glfw_windowBuilder.cpp core/glfw_windowBuilder.hpp
	${CXX} ${CPPFLAGS} -c -g core/glfw_windowBuilder.cpp	

#imgui_mod_back
im_gui_modifed_backends.o: gui/im_gui_modifed_backends.cpp gui/im_gui_modifed_backends.hpp core/opengl_utility.hpp
	${CXX} ${CPPFLAGS} -I${IMGUI_INC} -I${IMGUI_BACKENDS_INC} -c -g gui/im_gui_modifed_backends.cpp

#imgui lib
imgui.o: ../3rd_party/imgui/imgui.cpp 
	${CXX} ${CPPFLAGS} -I${IMGUI_INC} -I${IMGUI_BACKENDS_INC} -c -g ../3rd_party/imgui/imgui.cpp 
imgui_draw.o: ../3rd_party/imgui/imgui_draw.cpp
	${CXX} ${CPPFLAGS} -I${IMGUI_INC} -I${IMGUI_BACKENDS_INC} -c -g ../3rd_party/imgui/imgui_draw.cpp
imgui_tables.o: ../3rd_party/imgui/imgui_tables.cpp 				
	${CXX} ${CPPFLAGS} -I${IMGUI_INC} -I${IMGUI_BACKENDS_INC} -c -g ../3rd_party/imgui/imgui_tables.cpp  
imgui_widgets.o: ../3rd_party/imgui/imgui_widgets.cpp 
	${CXX} ${CPPFLAGS} -I${IMGUI_INC} -I${IMGUI_BACKENDS_INC} -c -g ../3rd_party/imgui/imgui_widgets.cpp 
imgui_impl_opengl3.o: ../3rd_party/imgui/backends/imgui_impl_opengl3.cpp
	${CXX} ${CPPFLAGS} -I${IMGUI_INC} -I${IMGUI_BACKENDS_INC} -c -g  ../3rd_party/imgui/backends/imgui_impl_opengl3.cpp


.PHONY : clean_render
clean_render:
	-rm gui_yahoo_combo.o opengl_utility.o glfw_windowBuilder.o 

.PHONY : clean_modback
clean_modback:
	-rm gui_yahoo_combo.o im_gui_modifed_backends.o

PHONY : clean_imgui_lib
clean_imgui_lib:
	-rm gui_yahoo_combo.o imgui.o imgui_draw.o imgui_tables.o imgui_widgets.o imgui_impl_opengl3.o

.PHONY : clean_thread
clean_thread:
	-rm gui_yahoo_combo.o custom_hash.o

.PHONY : clean_yah
clean_yah:
	-rm gui_yahoo_combo.o quote_spot_yah.o quote_bank.o	

.PHONY : clean_parse
clean_parse:
	-rm gui_yahoo_combo.o parser_yah.o	

.PHONY : clean_eng
clean_eng:
	-rm engine.o 
	
.PHONY : clean
clean :
	-rm atomthreadtest $(OBJS)



