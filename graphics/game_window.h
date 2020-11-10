#ifndef GAME_WINDOW
#define GAME_WINDOW

#include <stdbool.h>
#include "ogl_context.h"
#include <GLFW/glfw3.h>
#include "../libs/error.h"
#include "../types.h"

/* GameWindow struct containing necessary information about a game window. 
 * The changes bitField contains which values were changed. */
typedef struct GameWindow {
	char*	title;
	float	screenSizeX;
	float	screenSizeY;
	bool	mouseCaptured;
	bool	fullScreen;
	Color	backgroundColor;
	char	changesBitField; 
	GLFWwindow*	openGlWindow;
} GameWindow;

/* GameWindow functions
 * they all get a game window as a parameter and return a status code. */
int	gameWindow_add	(GameWindow*	window, char*	windowTitle);

int	gameWindow_setMouseCaptured	(GameWindow*	window, bool	captured);

int	gameWindow_setScreenSize	(GameWindow*	window, int	x, int	y);

int	gameWindow_getScreenSize	(GameWindow*	window, int	*x, int	*y);

int	gameWindow_setFullScreen	(GameWindow*	window, bool	fullScreen);

int	gameWindow_setBackgroundColor	(GameWindow*	window, Color	color);

int	gameWindow_checkWindow	(GameWindow*	window);

int	gameWindow_bind		(GameWindow*	window);

int	gameWindow_remove	(GameWindow*	window);

int	gameWindow_update	(GameWindow*	window); 

#endif
