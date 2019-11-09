#include "Render.h"

int Render::createWindow() {

	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, "Return of the Learn OpenGL for Exercices\, with a vengeance", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);

	/* Para nunca esquecer.
	The first two parameters of glViewport set the location of the lower left corner of the window. 
	The third and fourth parameter set the width and height of the rendering window in pixels, which we set equal to GLFW's window size.
	*/
	glViewport(0, 0, width, height);

}


