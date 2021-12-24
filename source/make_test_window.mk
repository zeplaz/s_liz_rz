#makefile test error code
CXX = g++
CPPFLAGS = -std=c++20 -pg -fconcepts-ts  -Wall -pedantic 
LINKERFLAG =  -lcurl -lfmt -lpthread -lGLEW -lglfw -lGLU -lSDL2 -lSDL2main -lSDL2_image -lSDL2_ttf -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl 
LIBSTD06   =  /usr/lib64/libstdc++.so.6

THRID_PARTY_INCLUDE ="../3rd_party" 
IMGUI_INC           ="../3rd_party/imgui"
IMGUI_BACKENDS_INC  ="../3rd_party/imgui/backends"

FMT_INCLUDE = /usr/local/include/fmt

CORE = engine.o
RENDER =  render.o SDL_window.o sdl_window_imp.o glfw_windowBuilder.o opengl_utility.o
IMGUI_LIB = imgui.o imgui_draw.o imgui_tables.o imgui_widgets.o imgui_impl_opengl3.o imgui_impl_sdl.o
GUI = imgui_controler.o im_gui_modifed_backends.o 
OBJS = ut_windows_01.o  ${CORE} ${RENDER} ${GUI} ${IMGUI_LIB} 

windowtest: ${OBJS}
	${CXX} ${CPPFLAGS} ${OBJS} -L$(LIBSTD06) ${LINKERFLAG}  -o windowtest 

#main 
ut_windows_01.o: testz/ut_windows_01.cpp 
	${CXX} ${CPPFLAGS} -c -g testz/ut_windows_01.cpp

#core
engine.o: core/engine.cpp core/engine.hpp
	${CXX} ${CPPFLAGS} -c -g core/engine.cpp

# render 
render.o: core/render/render.cpp core/render/render.hpp
		${CXX} ${CPPFLAGS} -I${IMGUI_INC} -I${IMGUI_BACKENDS_INC} -c -g core/render/render.cpp

opengl_utility.o: core/render/opengl_utility.cpp core/render/opengl_utility.hpp
	${CXX} ${CPPFLAGS} -c -g core/render/opengl_utility.cpp

glfw_windowBuilder.o: core/render/glfw_windowBuilder.cpp core/render/glfw_windowBuilder.hpp core/render/opengl_utility.hpp
	${CXX} ${CPPFLAGS} -c -g core/render/glfw_windowBuilder.cpp			

SDL_window.o: core/render/SDL_window.cpp core/render/SDL_window.hpp core/render/opengl_utility.hpp
	${CXX} ${CPPFLAGS} -c -g core/render/SDL_window.cpp 

sdl_window_imp.o: core/render/sdl_window_imp.cpp core/render/SDL_window.hpp core/render/opengl_utility.hpp
	${CXX} ${CPPFLAGS} -c -g core/render/sdl_window_imp.cpp 	
#GUI
imgui_controler.o: gui/imgui_controler.hpp gui/imgui_controler.cpp 
	${CXX} ${CPPFLAGS} -I${IMGUI_INC} -I${IMGUI_BACKENDS_INC} -c -g gui/imgui_controler.cpp 

im_gui_modifed_backends.o: gui/im_gui_modifed_backends.cpp gui/im_gui_modifed_backends.hpp core/render/opengl_utility.hpp
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
imgui_impl_sdl.o: ../3rd_party/imgui/backends/imgui_impl_sdl.cpp
	${CXX} ${CPPFLAGS} -I${IMGUI_INC} -I${IMGUI_BACKENDS_INC} -c -g ../3rd_party/imgui/backends/imgui_impl_sdl.cpp
imgui_impl_opengl3.o: ../3rd_party/imgui/backends/imgui_impl_opengl3.cpp
	${CXX} ${CPPFLAGS} -I${IMGUI_INC} -I${IMGUI_BACKENDS_INC} -c -g ../3rd_party/imgui/backends/imgui_impl_opengl3.cpp

.PHONY : clean_all
clean_all :
	-rm windowtest  $(OBJS)

.PHONY : clean
clean :
	-rm windowtest  ut_windows_01.o  ${CORE} ${RENDER} ${GUI}