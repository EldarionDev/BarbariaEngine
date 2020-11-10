#include "game_window.h"

int	gameWindow_add	(GameWindow*	window, char*	windowTitle) {
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	const GLFWvidmode*	video_mode	=	glfwGetVideoMode(glfwGetPrimaryMonitor());
	if	(video_mode == NULL)	return	GlfwError;
	else if	(video_mode->width == 0 || video_mode->height == 0)	return	UnexpectedZeroValue;
	else if	(video_mode->width < 0 || video_mode->height == 0)	return	UnexpectedSmallValue;

	window->screenSizeX	=	video_mode->width;
	window->screenSizeY	=	video_mode->height;
	window->openGlWindow	=	glfwCreateWindow(video_mode->width, video_mode->height, windowTitle, glfwGetPrimaryMonitor(), NULL);
	if	(window == NULL)	return	GlfwError;
	window->mouseCaptured	=	false;
	window->title	=	windowTitle;
	
	glfwMakeContextCurrent(window->openGlWindow);
	
	int	context_status	=	oglContext_initContext();
	if	(context_status != NoError)	return	context_status;
	return	NoError;
}

int	gameWindow_setMouseCaptured	(GameWindow*	window, bool	captured) {
	if	(gameWindow_checkWindow(window) != NoError)	return 	gameWindow_checkWindow(window);
	window->mouseCaptured	=	captured;
	return	NoError;
}

int	gameWindow_setScreenSize	(GameWindow*	window, int	x, int	y) {
	if	(gameWindow_checkWindow(window) != NoError)	return 	gameWindow_checkWindow(window);
	if	(x == 0 || y == 0)	return	UnexpectedZeroValue;
	if	(x < 0 || y < 0)	return	UnexpectedSmallValue;
	window->screenSizeX	=	x;
	window->screenSizeY	=	y;
	window->changesBitField	|=	0x8;
	return NoError;
}

int	gameWindow_getScreenSize	(GameWindow*	window, int	*x, int	*y) {
	if	(gameWindow_checkWindow(window) != NoError)	return 	gameWindow_checkWindow(window);
	if	(x == NULL || y == NULL) return	NullPointerError;
	*x	=	window->screenSizeX;
	*y	=	window->screenSizeY;
	return NoError;
}

int	gameWindow_setFullScreen	(GameWindow*	window, bool	fullScreen) {
	if	(gameWindow_checkWindow(window) != NoError)	return	gameWindow_checkWindow(window);
	window->fullScreen	=	fullScreen;
	const GLFWvidmode*	video_mode	=	glfwGetVideoMode(glfwGetPrimaryMonitor());
	if	(video_mode->width == 0 || video_mode->height == 0)	return	UnexpectedZeroValue;
	else if	(video_mode->width < 0 || video_mode->height == 0)	return	UnexpectedSmallValue;
	window->screenSizeX	=	video_mode->width;
	window->screenSizeY	=	video_mode->height;
	window->changesBitField	|=	0x4;
	window->backgroundColor	=	(Color) {.r = 0.0f, .g = 0.0f, .b = 0.0f, .a = 0.0};
	return NoError;
}

int	gameWindow_setBackgroundColor	(GameWindow*	window, Color	color) {
	if	(gameWindow_checkWindow(window) != NoError)	return 	gameWindow_checkWindow(window);
	window->backgroundColor	=	(Color) {.r = color.r, .g = color.g, .b = color.b, .a = color.a};
	return NoError;
}

int	gameWindow_checkWindow	(GameWindow*	window) {
	if	(window == NULL)	return	NullPointerError;
	if	(window->screenSizeX == 0 || window->screenSizeY == 0)	return	UnexpectedZeroValue;
	if	(window->screenSizeX < 0 || window->screenSizeY < 0)	return	UnexpectedSmallValue;
	if	(window->openGlWindow == NULL)	return	NullPointerError;
	return	NoError;
}

int	gameWindow_update	(GameWindow*	window) {
	if	(gameWindow_checkWindow(window) != NoError)	return 	gameWindow_checkWindow(window);
	if	((window->changesBitField & 0x8) == window->changesBitField) {
		/* Change resolution */
		window->openGlWindow	=	glfwCreateWindow(window->screenSizeX, window->screenSizeY, window->title, glfwGetPrimaryMonitor(), NULL);
		glfwMakeContextCurrent(window->openGlWindow);
		int	context_status	=	oglContext_initContext();
		return	context_status; 
	}
	if	((window->changesBitField & 0x4) == window->changesBitField) {
		/* Change full screen */
		window->openGlWindow	=	glfwCreateWindow(window->screenSizeX, window->screenSizeY, window->title, glfwGetPrimaryMonitor(), NULL);
		glfwMakeContextCurrent(window->openGlWindow);
		int	context_status	=	oglContext_initContext();
		return	context_status;
	}
	oglContext_clearScreen((Color) {.r = window->backgroundColor.r, .g = window->backgroundColor.g, .b = window->backgroundColor.b, .a = window->backgroundColor.a});
	oglContext_clearBuffers();
	glfwSwapBuffers(window->openGlWindow);
	return	NoError;
}

int	gameWindow_bind		(GameWindow*	window) {
	if	(gameWindow_checkWindow(window) != NoError)	return 	gameWindow_checkWindow(window);
	glfwMakeContextCurrent(window->openGlWindow);
	int	context_status	=	glfwInit();
	return	context_status;
}

int	gameWindow_remove	(GameWindow*	window) {
	if	(gameWindow_checkWindow(window) != NoError)	return 	gameWindow_checkWindow(window);
	glfwDestroyWindow(window->openGlWindow);
	window	=	NULL;	
	return NoError;
}
