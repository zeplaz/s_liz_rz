//opengl
#ifndef SLAZERZ_01_OPENGL_UTILITY_001_HPP
#define SLAZERZ_01_OPENGL_UTILITY_001_HPP
//#define GLFW_INCLUDE_NONE       // GLFW including OpenGL headers causes ambiguity or multiple definition errors.

#include <stdio.h>


#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_SWIZZLE // Enable GLM Swizzling, must be before glm is included!
#include <glm/glm.hpp> // glm::mat4
#include <glm/ext.hpp> // perspective, translate, rotate

//#include <glbinding/gl/gl.h>
//#include <glbinding/Binding.h>  // Initialize with glbinding::Binding::initialize()





void APIENTRY GLAPIENTRY glDebugOutput(GLenum source,
                         GLenum type,
                         GLuint id,
                         GLenum severity,
                         GLsizei length,
                         const GLchar *message,
                         const void *userParam);


static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}


#endif