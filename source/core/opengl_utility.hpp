//opengl
#ifndef SLAZERZ_01_OPENGL_UTILITY_001_HPP
#define SLAZERZ_01_OPENGL_UTILITY_001_HPP

#include <stdio.h>
#include <GL/glew.h>

#define GLFW_INCLUDE_NONE       // GLFW including OpenGL headers causes ambiguity or multiple definition errors.
#include <glbinding/Binding.h>  // Initialize with glbinding::Binding::initialize()
#include <glbinding/gl/gl.h>

namespace SL_ZER
{
    constexpr char* glsl_version = "#version 450";
    static char         g_GlslVersionString[32] = "";
    static GLuint       g_FontTexture = 0;
    static GLuint       g_ShaderHandle = 0, g_VertHandle = 0, g_FragHandle = 0;
    static int          g_AttribLocationTex = 0, g_AttribLocationProjMtx = 0;
    static int          g_AttribLocationPosition = 0, g_AttribLocationUV = 0, g_AttribLocationColor = 0;
    static unsigned int g_VboHandle = 0, g_ElementsHandle = 0;
}

#define APIENTRY GLAPIENTRY
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