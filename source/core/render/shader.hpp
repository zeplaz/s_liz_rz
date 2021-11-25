
struct shader
{
	shader()
	{
	 gProgramID = glCreateProgram();

	}

		//Graphics program
	GLuint gProgramID = 0;
	



	void load_vertex_shader(const GLchar* vertexShaderSource, GLsizei count = 0, const GLint* length  = NULL)
	{

	//Create vertex shader
	GLuint vertexShader = glCreateShader( GL_VERTEX_SHADER );
	glShaderSource( vertexShader, count, vertexShaderSource, length);

	//Compile vertex source
	glCompileShader( vertexShader );


	//Check vertex shader for errors
	GLint vShaderCompiled = GL_FALSE;
	glGetShaderiv( vertexShader, GL_COMPILE_STATUS, &vShaderCompiled );
	if( vShaderCompiled != GL_TRUE )
	{
		printf( "Unable to compile vertex shader %d!\n", vertexShader );
		printShaderLog( vertexShader );
        success = false;
	}
	else
	{
		//Attach vertex shader to program
		glAttachShader( gProgramID, vertexShader );
	}
}

	void load_fragment_shader(const GLchar* fragmentShaderSource, GLsizei count = 0, const GLint* length  = NULL)
	{
		GLuint fragmentShader = glCreateShader( GL_FRAGMENT_SHADER );
			glShaderSource( fragmentShader, count, fragmentShaderSource, length);

		//Compile fragment source
		glCompileShader( fragmentShader );

		//Check fragment shader for errors
		GLint fShaderCompiled = GL_FALSE;
		glGetShaderiv( fragmentShader, GL_COMPILE_STATUS, &fShaderCompiled );
		if( fShaderCompiled != GL_TRUE )
		{
			printf( "Unable to compile fragment shader %d!\n", fragmentShader );
			printShaderLog( fragmentShader );
			success = false;
		}
		else
		{
			//Attach fragment shader to program
			glAttachShader( gProgramID, fragmentShader );

						//Link program
			glLinkProgram( gProgramID );

			//Check for errors
			GLint programSuccess = GL_TRUE;
			glGetProgramiv( gProgramID, GL_LINK_STATUS, &programSuccess );
			if( programSuccess != GL_TRUE )
			{
				printf( "Error linking program %d!\n", gProgramID );
				printProgramLog( gProgramID );
				success = false;
			}
		}
	}

	void render()
	{
		glUseProgram( gProgramID );

				//Enable vertex position
		glEnableVertexAttribArray( gVertexPos2DLocation );

		//Set vertex data
		glBindBuffer( GL_ARRAY_BUFFER, gVBO );
		glVertexAttribPointer( gVertexPos2DLocation, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), NULL );

		//Set index data and render
		glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, gIBO );
		glDrawElements( GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, NULL );

		//Disable vertex position
		glDisableVertexAttribArray( gVertexPos2DLocation );
		//Unbind program
		glUseProgram( NULL );

	}


	void close()
	{
			//Deallocate program
	glDeleteProgram( gProgramID );
	}


void printProgramLog( GLuint program )
{
	//Make sure name is shader
	if( glIsProgram( program ) )
	{
		//Program log length
		int infoLogLength = 0;
		int maxLength = infoLogLength;
		
		//Get info string length
		glGetProgramiv( program, GL_INFO_LOG_LENGTH, &maxLength );
		
		//Allocate string
		char* infoLog = new char[ maxLength ];
		
		//Get info log
		glGetProgramInfoLog( program, maxLength, &infoLogLength, infoLog );
		if( infoLogLength > 0 )
		{
			//Print Log
			printf( "%s\n", infoLog );
		}
		
		//Deallocate string
		delete[] infoLog;
	}
	else
	{
		printf( "Name %d is not a program\n", program );
	}
}

void printShaderLog( GLuint shader )
{
	//Make sure name is shader
	if( glIsShader( shader ) )
	{
		//Shader log length
		int infoLogLength = 0;
		int maxLength = infoLogLength;
		
		//Get info string length
		glGetShaderiv( shader, GL_INFO_LOG_LENGTH, &maxLength );
		
		//Allocate string
		char* infoLog = new char[ maxLength ];
		
		//Get info log
		glGetShaderInfoLog( shader, maxLength, &infoLogLength, infoLog );
		if( infoLogLength > 0 )
		{
			//Print Log
			printf( "%s\n", infoLog );
		}

		//Deallocate string
		delete[] infoLog;
	}
	else
	{
		printf( "Name %d is not a shader\n", shader );
	}
}


};


struct shader_data
{
	GLint VertexPos_Location = -1;
	GLuint gVBO = 0;
	GLuint gIBO = 0;
};