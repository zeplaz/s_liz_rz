//render



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


	glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync	

	window = glfwCreateWindow(DEFAULT_WIDTH, DEFAULT_HIGHT, "slezzer", NULL, NULL);
    if (window == NULL)
        return 1;

    glbinding::initialize([](const char* name) { return (glbinding::ProcAddress)glfwGetProcAddress(name); });

	bool err = glewInit() != GLEW_OK;

	  if (err)
    {
        fprintf(stderr, "Failed to initialize OpenGL loader!\n");
        return 1;
    }

}

void render::shutdown()
{
		if (g_VboHandle) glDeleteBuffers(1, &g_VboHandle);
	    if (g_ElementsHandle) glDeleteBuffers(1, &g_ElementsHandle);
	    g_VboHandle = g_ElementsHandle = 0;

	    if (g_ShaderHandle && g_VertHandle) glDetachShader(g_ShaderHandle, g_VertHandle);
	    if (g_VertHandle) glDeleteShader(g_VertHandle);
	    g_VertHandle = 0;

	    if (g_ShaderHandle && g_FragHandle) glDetachShader(g_ShaderHandle, g_FragHandle);
	    if (g_FragHandle) glDeleteShader(g_FragHandle);
	    g_FragHandle = 0;

	    if (g_ShaderHandle) glDeleteProgram(g_ShaderHandle);
	    g_ShaderHandle = 0;

}




void render_gui_mgmt::setup_imgui()
	{
		IMGUI_CHECKVERSION();
	    ImGui::CreateContext();
	    ImGuiIO& gui_io = ImGui::GetIO();
	    (void)gui_io;
	    gui_io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
	    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

	    // Setup Dear ImGui style
	    ImGui::StyleColorsDark();
	    //ImGui::StyleColorsClassic();	
		ImGui_ImplGlfw_InitForOpenGL(window, true);
		
		 IM_ASSERT((int)strlen(glsl_version) + 2 < IM_ARRAYSIZE(g_GlslVersionString));
	    strcpy(g_GlslVersionString, glsl_version);
	    strcat(g_GlslVersionString, "\n");

		gui_io.BackendRendererName  = "imgui_mofifed_opengl_4.5";
	}

void render_gui_mgmt::shutdown()
	{
		
	    ///delite textures

	     if (gui_FontTexture)
	    {
	        ImGuiIO& io = ImGui::GetIO();
	        glDeleteTextures(1, &g_FontTexture);
	        io.Fonts->TexID = 0;
	        g_FontTexture = 0;
	    }

    }