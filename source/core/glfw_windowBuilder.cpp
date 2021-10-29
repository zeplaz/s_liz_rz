

#include "opengl_utility.hpp"
#include "glfw_windowBuilder.hpp"
#include "utilityz/errorhandler.hpp"


#include <iostream>

window_glfw::~window_glfw()
  {
   this->shutdown();
  }

void window_glfw::shutdown()
 {
   if(window != nullptr)
   glfwDestroyWindow(window);

  #ifdef DEBUG_01
 std::cout<< ""

  #endif

  }

  int window_glfw::is_window_open()
  {	

  	return glfwWindowShouldClose(window);
   
  }

bool windows_MGMT::poll_tno_close()
    {   
       // std::cout << "polling for close window..\n";
      glfwPollEvents();
      for(auto it =  w_map.begin(); it != w_map.end(); it++)
        {   
            int win =  it->second->is_window_open();
            std::cout << "window to be closed?;" << win << "\n";
            if( 0 != win)
            { 
                std::cout << "window to be closed;\n";
                it->second->shutdown();
                w_map.remove(it->first);
                open_windows--;
            }
        }
        if(open_windows <1)
        { 
          return false;
        }
        else
        {
          return true;     
        }        
    }
ERRORCODE window_glfw::setup_glfw_context()
{
	glfwSetErrorCallback(glfw_error_callback);	
	glewExperimental = GL_TRUE;
	//launch gluitInit

	if (!glfwInit())
	{	

	 	std::cout << "##ERROR:::glfwinit faild :()\n";
		return GWFLW_FAIL_INIT;
	}

	std::cout << "glfwInit compleated\n";

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,5);
	
	#ifdef  DEBUG_01
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GL_TRUE);
	#endif

	glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
	return NO_ERROR; 
}


ERRORCODE window_glfw::create_window(int width, int hight, std::string title)
{

	window = glfwCreateWindow(width,hight,title.c_str(), NULL, NULL);
   
   if (window == NULL)  
      {
       std::cout << "ERROR..glfwCreateWindow.window NULL\n";
       return GWFLW_FAIL_CREATE;
      } 

	
	std::cout << "window created? compleated\n";

	glfwMakeContextCurrent(window);
  glfwSwapInterval(1); // Enable vsync	

  

  set_viewport_callback();
  set_windowSize_callback();
  
  #ifdef DEBUG_01
 // set_debug_context();
  #endif
  
  std::cout << "glewcheck::"<< error_to_string(glew_check()) << '\n'; 

  return NO_ERROR;
}

ERRORCODE window_glfw::glew_check()
{
   // glbinding::initialize([](const char* name) { return (glbinding::ProcAddress)glfwGetProcAddress(name); });

	GLenum err = glewInit() != GLEW_OK;

	  if (err)
    {	
    	std::cout << "\n ERROR::glew_code::" << err <<'\n' <<'\n';
    	std::cout << "GLEW Error: " << glewGetErrorString(err) <<'\n'; 
      fprintf(stderr, "Failed to initialize OpenGL loader!\n");
        return GLEW_FAIL;
    }
    return NO_ERROR;
}


//x, y Specify the lower left corner of the viewport rectangle, in pixels. The initial value is (0,0). 

void window_glfw::set_viewport_callback()
{
	 glfwSetFramebufferSizeCallback(window,[](GLFWwindow* window,int width ,int height)
	 {
	 	 glViewport(0, 0, width, height);

	 });		
}



void windows_MGMT::set_windowSize_callback()
{
	
  curr_window = nullptr;
  glfwSetWindowSizeCallback(window,[](GLFWwindow* window, int w, int h)
	{

     for (auto& itr : g_lWindows)
     {
          if (itr->m_pWindow == a_pWindow)
          {
               window = itr;
               window->m_uiWidth = a_iWidth;
               window->m_uiHeight = a_iHeight;
               window->m_m4Projection = glm::perspective(45.0f, float(a_iWidth)/float(a_iHeight), 0.1f, 1000.0f);
          }
     }
 
     WindowHandle previousContext = g_hCurrentContext;
     MakeContextCurrent(window);
     glViewport(0, 0, a_iWidth, a_iHeight);
     MakeContextCurrent(previousContext);


    glfwSetWindowSize(window, w, h);    
	});


  // find the window data corrosponding to a_pWindow;
    
 
    
}

}

void window_glfw::set_debug_context()
{
	GLint flags;
	glGetIntegerv(GL_CONTEXT_FLAGS, &flags);

if (flags & GL_CONTEXT_FLAG_DEBUG_BIT)
{
	std::cout <<"GLFW_WINDOW::debug iniaizled\n";
  
  glEnable(GL_DEBUG_OUTPUT);
  glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
  glDebugMessageCallback(glDebugOutput, nullptr);
  glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DONT_CARE, 0, nullptr, GL_TRUE);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}
}
