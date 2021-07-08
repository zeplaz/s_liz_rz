

#


CXX = g++
CPPFLAGS = -std=c++20 -pg -fconcepts-ts

LINKERFLAG = -lcurl -lcrypto -lwebsockets -lbinacpp -ljsoncpp -lpthread -lGLEW -lglfw -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl 

THRID_PARTY_INCLUDE = "../3rd_party" 
IMGUI_BACKEND_INCLUDE = "../3rd_party/imgui/backends" 
IMGUI_INCLUDE= "../3rd_party/imgui"  
BIANCE_INCLUDE = "../3rd_party/binacpp/lib/libbinacpp/include"

OBJS = price_point_cmder.o ut_engine_0.1.o imgui_impl_opengl3.o render.o locks.o gui_MCP.o opengl_utility.o imgui.o imgui_draw.o imgui_tables.o imgui_widgets.o



sl_zerz: ${OBJS}
		${CXX} ${CPPFLAGS} ${LINKERFLAG}  ${OBJS} ${LINKERFLAG} -o slz_zerz

engine.o: core/engine.cpp core/engine.hpp
	${CXX} ${CPPFLAGS} -c -g core/engine.cpp

ut_engine_0.1.o: testz/ut_engine_0.1.cpp 
	${CXX} ${CPPFLAGS} -I$(IMGUI_INCLUDE) -I$(IMGUI_BACKEND_INCLUDE) -c -g testz/ut_engine_0.1.cpp

imgui_impl_opengl3.o: ../3rd_party/imgui/backends/imgui_impl_opengl3.cpp ../3rd_party/imgui/backends/imgui_impl_opengl3.h
	${CXX} ${CPPFLAGS} -I$(IMGUI_INCLUDE) -I$(IMGUI_BACKEND_INCLUDE) -I$(THRID_PARTY_INCLUDE) -c -g ../3rd_party/imgui/backends/imgui_impl_opengl3.cpp 

opengl_utility.o: core/opengl_utility.cpp core/opengl_utility.hpp 
	${CXX} ${CPPFLAGS} -c -g core/opengl_utility.cpp

render.o: core/render.cpp core/render.hpp
	${CXX} ${CPPFLAGS} -c -g core/render.cpp  

gui_MCP.o:  core/opengl_utility.hpp gui/gui_MCP.cpp gui/gui_MCP.hpp
	${CXX} ${CPPFLAGS} -I$(IMGUI_INCLUDE) -c -g gui/gui_MCP.cpp

price_point_cmder.o:	core/price_point_cmder.hpp core/price_point_cmder.cpp  
	${CXX} ${CPPFLAGS} -I$(THRID_PARTY_INCLUDE) -c -g  core/price_point_cmder.cpp  

locks.o: core/utilityz/locks.cpp core/utilityz/locks.hpp
	${CXX} ${CPPFLAGS} -I$(THRID_PARTY_INCLUDE) -c -g core/utilityz/locks.cpp 

imgui.o: ../3rd_party/imgui/imgui.cpp ../3rd_party/imgui/imgui.h 
	${CXX} ${CPPFLAGS} -I$(IMGUI_INCLUDE) -c -g ../3rd_party/imgui/imgui.cpp 

imgui_draw.o:	../3rd_party/imgui/imgui_draw.cpp 
	${CXX} ${CPPFLAGS} -I$(IMGUI_INCLUDE) -c -g ../3rd_party/imgui/imgui_draw.cpp 
imgui_tables.o:	../3rd_party/imgui/imgui_tables.cpp 
	${CXX} ${CPPFLAGS} -I$(IMGUI_INCLUDE) -c -g ../3rd_party/imgui/imgui_tables.cpp 
imgui_widgets.o:	../3rd_party/imgui/imgui_widgets.cpp 
	${CXX} ${CPPFLAGS} -I$(IMGUI_INCLUDE) -c -g ../3rd_party/imgui/imgui_widgets.cpp 
