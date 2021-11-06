///input_cotroler


#ifndef SLAZERZ_01_INPUT_CONTROLERZ_GLFW_001_HPP
#define SLAZERZ_01_INPUT_CONTROLERZ_GLFW_001_HPP



//forward delc

#include "../core/opengl_utility.hpp"

class input_handles_glfw {
  //  void handleInput(GLFWwindow *window, );
    void handle_mouse(GLFWwindow* window, double x, double y);
    void handle_scroll(GLFWwindow* window, double xoffset, double yoffset);
  
    void handle_keys(GLFWwindow* window, float delta);
 
    void handle_charkey(GLFWwindow* window, char key);
};

 struct  mouse_params_t
 {	

 	float last_Mouse_posX  = 0.0f;
	float last_Mouse_posy  = 0.0f;
	bool  first_Mouse_move = true; 
	
 	bool lbutton_down = false;
	bool rbutton_down = false; 
	bool middle_down = false; 

	bool has_secondary = false;

	std::vector<bool> secondary_buttons; 


	void n_secondary_buttons(std::size_t n)
	{
		secondary_buttons.resize(n,false); 
	}

 };


class input_glfw_ctl
{
	protected :

	mouse_params_t mouse_pramz; 
	input_handles_glfw glfw_input_ctlz;

	public : 
	void set_callbacks(LFWwindow* window)
	{
		glfwSetWindowUserPointer(window, &glfw_input_ctlz);


		glfwSetCursorPosCallback(window,
								[](GLFWwindow *window, double x, double y)
								{
									if (input_handles_glfw *controls = static_cast<input_controls_glfw*>(glfwGetWindowUserPointer(window)))
							    	{
							    	 controls->handle_mouse(window, x, y);
							    	}
								}
								);

		glfwSetScrollCallback(window,
								[](GLFWindow *window, double xoffset, double yoffset)
								{
									if (input_controls_glfw *controls = static_cast<input_controls_glfw*>(glfwGetWindowUserPointer(window)))
									{
									 controls->Handle_scroll(window,xoffset,yoffset);	
									}
								}
								);

	
		glfwSetMouseButtonCallback(window, 
								[](GLFWindow *window, int button, int action, int mods)
								{
									if (input_controls_glfw *controls = static_cast<input_controls_glfw*>(glfwGetWindowUserPointer(window)))
									{
									controls->handle_mouse_buttons(window,button, action, mods);
									}
								}						
							   );

		

		glfwSetKeyCallback(window,
			[](GLFWwindow* window,)
	}
};

/*

void handle_keys(GLFWwindow* win, float delta)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
	//			glfwSetWindowShouldClose(window, true);
	}


}


void handle_mouse_buttons(GLFWwindow* window, int button, int action, int mods)
{	

	handle_dragz()


}
void handle_dragz (int button, int action, int mods)
{	


    if (button == GLFW_MOUSE_BUTTON_LEFT)
     {
        if(GLFW_PRESS == action)
            lbutton_down = true;
        else if(GLFW_RELEASE == action)
            lbutton_down = false;
    }

    if (button == GLFW_MOUSE_BUTTON_RIGHT)
     {
        if(GLFW_PRESS == action)
            lbutton_down = true;
        else if(GLFW_RELEASE == action)
            lbutton_down = false;
    }

    if(lbutton_down) 
    {
         // do your drag here
    }

    if(rbutton_down) 
    {
         // do your drag here
    }
} 


void HandleMouse(GLFWwindow* window, double x, double y)
	{
		if (first_Mouse_move)
		{
			last_Mouse_posX = x;
			last_Mouse_posy = y;
			first_Mouse_move = false;
		}

		float xoffset = x - last_Mouse_posX;
		float yoffset = last_Mouse_posy - y;
		last_Mouse_posX = x;
		last_Mouse_posy = y;

		float sensitivity = 0.1f;
		xoffset *= sensitivity;
		yoffset *= sensitivity;

		

  // `write your drag code here`

	}


	void HandleScroll(GLFWwindow* window, double xoffset, double yoffset)
	{
	
	}

    */


#endif