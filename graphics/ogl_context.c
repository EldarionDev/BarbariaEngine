#include "ogl_context.h"

int	oglContext_initContext	() {
	glewExperimental	=	1;
	GLenum	opengl_init_error	=	glewInit();
	if	(opengl_init_error != GLEW_OK)	return	OpenGlError;
	return	NoError;
}

int	oglContext_getVersion	(char*	version) {
	version	=	(char*) glGetString(GL_VERSION);
	if	(version == NULL)	return	NullPointerError;
	return	NoError;
}

int	oglContext_getVendor	(char*	vendor) {
	vendor	=	(char*) glGetString(GL_VENDOR);
	if	(vendor == NULL)	return	NullPointerError;
	return	NoError;
}

int	oglContext_getShaderLanguage	(char*	shaderLanguage) {
	shaderLanguage	=	(char*) glGetString(GL_SHADING_LANGUAGE_VERSION);
	if	(shaderLanguage == NULL)	return	NullPointerError;
	return	NoError;
}

int	oglContext_getRenderer	(char*	renderer) {
	renderer	=	(char*) glGetString(GL_RENDERER);
	if	(renderer == NULL)	return	NullPointerError;
	return	NoError;
}

void	oglContext_clearScreen	(Color color) {
	glClearColor(color.r, color.g, color.b, color.a);
}

void	oglContext_clearBuffers	() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

