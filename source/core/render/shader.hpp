
struct shader
{
	shader()
	{
	 gProgramID = glCreateProgram();

	}

		//Graphics program
	GLuint gProgramID = 0;
	GLint gVertexPos2DLocation = -1;
	GLuint gVBO = 0;
	GLuint gIBO = 0;


	void load_vertex_shader()
	{

	//Create vertex shader
	GLuint vertexShader = glCreateShader( GL_VERTEX_SHADER );
	glShaderSource( vertexShader, 1, vertexShaderSource, NULL );

	}



};
