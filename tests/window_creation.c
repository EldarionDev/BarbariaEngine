/* This is a test for a basic window creation using the Barbaria game engine. */

#include "../graphics/game_window.h"
#include <stdio.h>

int	main () {
	GameWindow*	testWindow;
	int status	=	gameWindow_add(testWindow, "Test Window");
	if	(status != NoError) printf("Error creating window. Aborting. Error Code: %d\n", status);
	gameWindow_setScreenSize(testWindow, 1920, 1080);
	status	=	gameWindow_setBackgroundColor(testWindow, (Color) {0.6f, 0.4f, 0.8f, 1.0f});
	if	(status != NoError) printf("Error setting color.. Aborting. Error Code: %d\n", status);
	while	(1) {
		int	status	=	gameWindow_update(testWindow);
		if	(status != NoError) printf("Error updating window. Aborting. Error Code: %d\n", status);
	}
}
