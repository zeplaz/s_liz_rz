struct gpu_opengl_handler
{

/*
GLsync glFenceSync( 	GLenum condition,
  	GLbitfield flags);

	*/

	void synic_testing()
	{
			GLsync waiton = glFenceSync(GL_SYNC_GPU_COMMANDS_COMPLETE,0);
	}
/*		ALREADY_SIGNALED                0x911A
        TIMEOUT_EXPIRED                 0x911B
        CONDITION_SATISFIED             0x911C
        WAIT_FAILED                     0x911D
*/
};
