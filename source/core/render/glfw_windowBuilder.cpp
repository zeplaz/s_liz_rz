

#include "glfw_windowBuilder.hpp"


window_glfw::~window_glfw()
  {
   this->shutdown();
  }



ERRORCODE window_glfw::init()
{
 ERRORCODE co = gl_window->setup_context();



  if(co != NO_ERROR)
  {
    #ifdef DEBUG_01
    fmt::print("\n##->ERROR CODE create_window::{}\n", error_to_string(co));
    #endif
    return co;
  }

  co = gl_window->create_window(DEFAULT_WIN_WIDTH,DEFAULT_WIN_HIGHT,MAIN_WIN_TITLE);

   if(co != NO_ERROR)
  {
    #ifdef DEBUG_01
    fmt::print("\n##->ERROR CODE create_window::{}\n", error_to_string(co));
    #endif
  return co;
  }
  
  co = gl_window->glew_check();
  
  #ifdef DEBUG_01
  fmt::print("\n##->ERROR CODE create_window::{}\n", error_to_string(co));
  #endif

  return  co; 

}

}

void window_glfw::render()
{
      //  int display_w, display_h;

    if(Resized == true)
        {if_resized();}
        
        glClearColor(CLEAR_COLOUR_GLM.x * CLEAR_COLOUR_GLM.w, CLEAR_COLOUR_GLM.y * CLEAR_COLOUR_GLM.w, CLEAR_COLOUR_GLM.z * CLEAR_COLOUR_GLM.w, CLEAR_COLOUR_GLM.w);
        glClear(GL_COLOR_BUFFER_BIT);
      
        //CALL IMGUI SHDRAW HERE!!!
        // ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
         /////
    
    glfwSwapBuffers(window);
}


void window_glfw::shutdown()
 {
   if(gwindow != nullptr)
   glfwDestroyWindow(window);

  #ifdef DEBUG_01
    fmt::print("\nwindow flfw shutdown likly destutor? showdown\n"); 

  #endif

  }

  int window_glfw::is_window_open()
  {	
  	return glfwWindowShouldClose(gwindow);
   
  }
 bool window_glfw::poll_to_close()
{
    glfwPollEvents();
    int win  = this->is_window_open();
      if( 0 != win)
      {
      return true; 
      }
      return false; 



}

ERRORCODE window_glfw::setup_context()
{
	glfwSetErrorCallback(glfw_error_callback);	
	glewExperimental = GL_TRUE;
	//launch gluitInit

	if (!glfwInit())
	{	

	 	fmt::print("\n##ERROR:::glfwinit faild :()\n");
		return GWFLW_FAIL_INIT;
	}

	fmt::print("\nglfwInit compleated\n");

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

	gWindow = glfwCreateWindow(width,hight,title.c_str(), NULL, NULL);
   
   if (gWindow == NULL)  
      {
       fmt::print("ERROR..glfwCreateWindow.window NULL\n");
       return GWFLW_FAIL_CREATE;
      } 

	#ifdef DEBUG_01
    fmt::print("\nwindow created? compleated\n");
    #endif
	glfwMakeContextCurrent(gWindow);
    glfwSwapInterval(1); // Enable vsync	

  
 // this->set_windowSize_callback();
  this->set_framebuffer_callback();
  
  glfwSetInputMode(gwindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  
  return NO_ERROR;
}

ERRORCODE window_glfw::glew_check()
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


//x, y Specify the lower left corner of the viewport rectangle, in pixels. The initial value is (0,0). 


void window_glfw::set_windowSize_callback()
{
	
   glfwSetWindowSizeCallback(gWindow,[](GLFWwindow* window, int w, int h)
	{               
     //glfwMakeContextCurrent(window);
     glfwSetWindowSize(window, w, h); 
     window_glfw::Resized = true;    
	   
    });
}

void window_glfw::set_framebuffer_callback()
{
glfwSetFramebufferSizeCallback(gWindow,[](GLFWwindow* window, int w, int h)
{
    glViewport(0, 0, w, h);
    window_glfw::Resized = true;   
}
);
}

void window_glfw::if_resized()
{
glfwGetWindowSize(gWindow, &frameportbuffer_width, &frameportbuffer_height);
//glfwSetWindowAspectRatio(window, frameportbuffer_width, frameportbuffer_height);
m_m4Projection = glm::perspective(45.0f, float(frameportbuffer_width)/float(frameportbuffer_height), 0.1f, 1000.0f);

Resized = false; 
}

  // find the window data corrosponding to a_pWindow;




