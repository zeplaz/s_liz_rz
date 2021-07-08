//render


#include "render.hpp"
#include <iostream>    



int render::setup_contex()
{

	glfwSetErrorCallback(glfw_error_callback);	
	glewExperimental = GL_TRUE;
	//launch gluitInit

	if (!glfwInit())
	{	

	 	std::cout << "flfwinit faild :()\n";
		return -1;
	}

	std::cout << "glfwInit compleated\n";

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,5);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(DEFAULT_WINDOW_WIDTH, DEFAULT_WINDOW_HIGHT, "slezzer", NULL, NULL);
    if (window == NULL)
       
       {
       	std::cout << "ERROR..glfwCreateWindow.window NULL\n";
       	return 1;
       } 

	std::cout << "window created? compleated\n";

	glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync	

	
	

   // glbinding::initialize([](const char* name) { return (glbinding::ProcAddress)glfwGetProcAddress(name); });

	GLenum err = glewInit() != GLEW_OK;

	  if (err)
    {	
    	std::cout << "glew_code::" << err <<'\n' <<'\n';
        fprintf(stderr, "Failed to initialize OpenGL loader!\n");
        return 1;
    }

    glViewport( 0, 0, MAIN_VEWPORT_WIDTH, MAIN_VEWPORT_HIGHT );
GLint flags;
glGetIntegerv(GL_CONTEXT_FLAGS, &flags);

if (flags & GL_CONTEXT_FLAG_DEBUG_BIT)
{
std::cout <<"debug iniaizled\n";
  glEnable(GL_DEBUG_OUTPUT);
  glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
glDebugMessageCallback(glDebugOutput, nullptr);
  glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);
}
return 0;
}

void render::shutdown()
{

}


