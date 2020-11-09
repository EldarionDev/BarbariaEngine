/* Status Code to be returned by functions.
 * 0 = No Error
 * <1 = Heap/Stack/Pointer error
 * >1 = Other runtime error. */
enum StatusCode {
	NoError	=	0,
	HeapAllocError	=	-1,
	HeapFreeError	=	-2,
	NullPointerError	=	-3,
	FileOpenError	=	1,
	FileCloseError	=	2,
	FileReadError	=	3,
	FileWriteError	=	4,
	OpenGlError	=	5,
	GlfwError	=	6,
	UnexpectedLargeValue	=	7,
	UnexpectedZeroValue	=	8,
	UnexpectedSmallValue	=	9
};
