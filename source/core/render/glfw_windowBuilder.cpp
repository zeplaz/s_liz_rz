

#include "glfw_windowBuilder.hpp"


window_glfw::~window_glfw()
  {
   this->shutdown();
  }



ERRORCODE window_glfw::init()
{
 ERRORCODE co = this->setup_context();

  if(co != NO_ERROR)
  {
    #ifdef DEBUG_01
    fmt::print("\n##->ERROR CODE create_window::{}\n", error_to_string(co));
    #endif
    return co;
  }

  co = this->create_window(DEFAULT_MAIN_VEWPORT_WIDTH,DEFAULT_MAIN_VEWPORT_HIGHT,"MAIN_WIN GLFW_TITLE");

   if(co != NO_ERROR)
  {
    #ifdef DEBUG_01
    fmt::print("\n##->ERROR CODE create_window::{}\n", error_to_string(co));
    #endif
 
  return co;
  }
  
  co = SL_ZER::glew_check();
  
  #ifdef DEBUG_01
  fmt::print("\n##->ERROR CODE create_window::{}\n", error_to_string(co));
  #endif

  return  co; 

}

void window_glfw::shutdown()
 {
   if(gWindow != nullptr)
   glfwDestroyWindow(gWindow);

  #ifdef DEBUG_01
    fmt::print("\nwindow flfw shutdown likly destutor? showdown\n"); 

  #endif

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
  
  glfwSetInputMode(gWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
  
  return NO_ERROR;
}


void window_glfw::set_windowSize_callback()
{
	
   glfwSetWindowSizeCallback(gWindow,[](GLFWwindow* window, int w, int h)
	{               
     glfwMakeContextCurrent(window);
     glfwSetWindowSize(window, w, h); 
     base_window::Resized = true;    
	   
    });
}

void window_glfw::set_framebuffer_callback()
{
glfwSetFramebufferSizeCallback(gWindow,[](GLFWwindow* window, int w, int h)
{
    glViewport(0, 0, w, h);
    base_window::Resized = true;   
}
);
}

void window_glfw::if_resized()
{
glfwGetWindowSize(gWindow, &frameportbuffer_width, &frameportbuffer_height);
//glfwSetWindowAspectRatio(window, frameportbuffer_width, frameportbuffer_height);
//m_m4Projection = glm::perspective(45.0f, float(frameportbuffer_width)/float(frameportbuffer_height), 0.1f, 1000.0f);

base_window::Resized = false; 
}

long double  glfw_window_imp::get_window_time_seconds()
{
  return glfwGetTime();    
}


void glfw_window_imp::render()
{
      //  int display_w, display_h;
    GLFWwindow*  l_window = static_cast<GLFWwindow*> (window->window_hanlde());  
    if(glfwWindowShouldClose(l_window))
      {window->shutdown_signa = true; 
        return; 
      }
    if(base_window::Resized == true)
        {window->if_resized();}
        
        glClearColor(CLEAR_COLOUR_GLM.x * CLEAR_COLOUR_GLM.w, CLEAR_COLOUR_GLM.y * CLEAR_COLOUR_GLM.w, CLEAR_COLOUR_GLM.z * CLEAR_COLOUR_GLM.w, CLEAR_COLOUR_GLM.w);
        glClear(GL_COLOR_BUFFER_BIT);
      
        //CALL IMGUI SHDRAW HERE!!!
        // ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
         /////
    
    glfwSwapBuffers(l_window);
}



 void glfw_window_imp::poll_events()
{
    glfwPollEvents();
}