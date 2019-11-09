#include <GLFW/glfw3.h>
#include <iostream>

#pragma once

class Render {

	GLFWwindow* window;
	int width, height;

public:
	int createWindow();	

	Render() { }
	Render(int w, int h) {
		width = w;
		height = h;
	}

	// Drawing
	void drawPlane();
	void drawTriangles();

	// Gets
	GLFWwindow* getWindow() {
		return window;
	}
};