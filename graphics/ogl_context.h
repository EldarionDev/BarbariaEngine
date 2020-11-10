#ifndef OGL_CONTEXT
#define OGL_CONTEXT

#include "../libs/error.h"
#include "../types.h"

#define GLEW_STATIC
#include <GL/glew.h>

int	oglContext_initContext	();

int	oglContext_getVersion	(char*	version);

int	oglContext_getVendor	(char*	vendor);

int	oglContext_getShaderLanguage	(char*	shaderLanguage);

int	oglContext_getRenderer	(char*	renderer);

void	oglContext_clearScreen	(Color color);

void	oglContext_clearBuffers	();

#endif
