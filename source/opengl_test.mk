#makefile for basetest opengl
CXX = g++
CPPFLAGS = -std=c++20 -pg -fconcepts-ts -Wall -pedantic

LINKERFLAG = -lpthread -lGLEW -lglfw -lGLU -lGL -lXrandr -lXxf86vm -lXi -lXinerama -lX11 -lrt -ldl 
OBJS = opengl_utility.o glfw_windowBuilder.o ut_renderer_0_1.o

opengl_test: ${OBJS}
	${CXX} ${CPPFLAGS} ${LINKERFLAG} ${OBJS} ${LINKERFLAG} -o opengl_test

glfw_windowBuilder.o: core/glfw_windowBuilder.cpp core/glfw_windowBuilder.hpp 
	${CXX} ${CPPFLAGS} -c -g core/glfw_windowBuilder.cpp	

opengl_utility.o: core/opengl_utility.cpp core/opengl_utility.hpp 
	${CXX} ${CPPFLAGS} -c -g core/opengl_utility.cpp	

ut_renderer_0_1.o: testz/ut_renderer_0_1.cpp
	${CXX} ${CPPFLAGS} -c -g testz/ut_renderer_0_1.cpp

.PHONY : clean
clean :
	-rm opengl_test $(OBJS)