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


#include "../utilityz/errorhandler.hpp"

const glm::vec4 CLEAR_COLOUR_GLM  {0.45f, 0.55f, 0.60f, 1.00f}; 

void APIENTRY GLAPIENTRY glDebugOutput(GLenum source,
                         GLenum type,
                         GLuint id,
                         GLenum severity,
                         GLsizei length,
                         const GLchar *message,
                         const void *userParam);


[[maybe_unused]] static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

namespace SL_ZER
{
 inline ERRORCODE glew_check()
 {

 // glbinding::initialize([](const char* name) { return (glbinding::ProcAddress)glfwGetProcAddress(name); });

    GLenum err = glewInit() != GLEW_OK;

    if (err)
    {   
     fmt::print("\n ###->SERROR::glew_code::{},\n GLEW Error::{}\n,",err,glewGetErrorString(err));

     fprintf(stderr, "Failed to initialize OpenGL loader!\n\n");
     return GLEW_FAIL;
    }
    
    return NO_ERROR;
}
}
#endif