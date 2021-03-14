#include <uinta/gl/gl_error.h>
#include <uinta/gl/gl_types.h>

#include <iostream> // TODO remove when logging is implemented

void checkGlAttachShader(GLenum err) {
	switch (err) {
		case GL_INVALID_VALUE:
			std::cerr << "glAttachShader GL_INVALID_VALUE: Either _program or _shader is not a value generated by ";
			std::cerr << "OpenGL." << std::endl;
			break;
		case GL_INVALID_OPERATION:
			std::cerr << "glAttachShader GL_INVALID_OPERATION: Either;";
			std::cerr << "\n\t1) _program is not a program object. Or,";
			std::cerr << "\n\t2) _shader is not a shader object. Or,";
			std::cerr << "\n\t3) _shader is already attached to program. Or,";
			std::cerr << "\n\t4) A shader of the same type as _shader is already attached to program." << std::endl;
			break;

		default:
			std::cerr << "Unknown glAttachShader error." << std::endl;
			break;
	}
}

void checkGlBindBuffer(GLenum err) {
	if (err == GL_INVALID_ENUM) {
		std::cerr << "glBindBuffer GL_INVALID_ENUM: _target is not one of the allowable values." << std::endl;
	} else {
		std::cerr << "Unknown glBindBuffer error." << std::endl;
	}
}

void checkGlBindTexture(GLenum err) {
	switch (err) {
		case GL_INVALID_ENUM:
			std::cerr << "glBindTexture GL_INVALID_ENUM: _target is not one of the allowable values." << std::endl;
			break;
		case GL_INVALID_OPERATION:
			std::cerr << "glBindTexture GL_INVALID_OPERATION: _texture was previously created with a target that doesn't match that of target." << std::endl;
			break;

		default:
			std::cerr << "Unknown glBindTexture error." << std::endl;
			break;
	}
}

void checkGlBindVertexArray(GLenum err) {
	if (err == GL_INVALID_OPERATION) {
		std::cerr << "glBindVertexArray GL_INVALID_OPERATION: _array is not zero or the name of a vertex array object ";
		std::cerr << "previously returned from a call to glGenVertexArrays." << std::endl;
	} else {
		std::cerr << "Unknown glBindVertexArray error." << std::endl;
	}
}

void checkGlBufferData(GLenum err) {
	switch (err) {
		case GL_INVALID_ENUM:
			std::cerr << "glBufferData GL_INVALID_ENUM: Either;";
			std::cerr << "\n\t1) _target is not one of the accepted buffer targets. Or,";
			std::cerr << "\n\t2) _usage is not GL_STREAM_DRAW, GL_STREAM_READ, GL_STREAM_COPY, GL_STATIC_DRAW, ";
			std::cerr << "GL_STATIC_READ, GL_STATIC_COPY, GL_DYNAMIC_DRAW, GL_DYNAMIC_READ, or GL_DYNAMIC_COPY.";
			std::cerr << std::endl;
			return;

		case GL_INVALID_VALUE:
			std::cerr << "glBufferData GL_INVALID_VALUE: Size is negative." << std::endl;
			return;

		case GL_INVALID_OPERATION:
			std::cerr << "glBufferData GL_INVALID_OPERATION: The reserved buffer object named 0 is bound to ";
			std::cerr << "target." << std::endl;
			return;

		case GL_OUT_OF_MEMORY:
			std::cerr << "glBufferData GL_INVALID_OPERATION: GL is unable to create a data store with the ";
			std::cerr << "specified size." << std::endl;
			return;

		default:
			std::cerr << "Unknown glBufferData error." << std::endl;
	}
}

void checkGlBufferSubData(GLenum err) {
	switch (err) {
		case GL_INVALID_ENUM:
			std::cerr << "glBufferSubData GL_INVALID_ENUM: Unacceptable VBO target type." << std::endl;
			return;

		case GL_INVALID_VALUE:
			std::cerr << "glBufferSubData GL_INVALID_VALUE: VBO offset or size is negative, or together they ";
			std::cerr << "define a region of memory that extends beyond the buffer object's allocated data store.";
			std::cerr << std::endl;
			return;

		case GL_INVALID_OPERATION:
			std::cerr << "glBufferSubData GL_INVALID_OPERATION: Either;";
			std::cerr << "\n\t1) The reserved buffer object name 0 is bound to target. Or,";
			std::cerr << "\n\t2) The buffer object being updated is mapped." << std::endl;
			return;


		default:
			std::cerr << "Unknown glBufferSubData error." << std::endl;
	}
}

void checkGlClear(GLenum err) {
	if (err == GL_INVALID_VALUE) {
		std::cerr << "glClear GL_INVALID_VALUE: _mask was not GL_DEPTH_CLEAR_VALUE, GL_COLOR_CLEAR_VALUE, or ";
		std::cerr << "GL_STENCIL_CLEAR_VALUE." << std::endl;
	} else {
		std::cerr << "Unknown glClear error." << std::endl;
	}
}

void checkGlCompileShader(GLenum err) {
	switch (err) {
		case GL_INVALID_VALUE:
			std::cerr << "glCompileShader GL_INVALID_VALUE: _shader is not a value generated by OpenGL." << std::endl;
			break;
		case GL_INVALID_OPERATION:
			std::cerr << "glCompileShader GL_INVALID_OPERATION: _shader is not a shader object." << std::endl;
			break;

		default:
			std::cerr << "Unknown glCompileShader error." << std::endl;
			break;
	}
}


#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedLocalVariable" // disables `err` unused warning

void checkGlCreateProgram(GLenum err) {
	// Intentionally empty. This method does not throw any errors as of OpenGL 4.5.
}

#pragma clang diagnostic pop

void checkGlCreateShader(GLenum err) {
	if (err == GL_INVALID_ENUM) {
		std::cerr << "glCreateShader GL_INVALID_ENUM: _shaderType is not an accepted value." << std::endl;
	} else {
		std::cerr << "Unknown glCreateShader error." << std::endl;
	}
}

void checkGlDeleteBuffers(GLenum err) {
	if (err == GL_INVALID_VALUE) {
		std::cerr << "glDeleteBuffers GL_INVALID_VALUE: _n is negative." << std::endl;
	} else {
		std::cerr << "Unknown glDeleteBuffers error." << std::endl;
	}
}

void checkGlDeleteShader(GLenum err) {
	if (err == GL_INVALID_VALUE) {
		std::cerr << "glDeleteShader GL_INVALID_VALUE: _shader is not a value generated by OpenGL." << std::endl;
	} else {
		std::cerr << "Unknown glDeleteShader error." << std::endl;
	}
}

void checkGlDeleteVertexArrays(GLenum err) {
	if (err == GL_INVALID_VALUE) {
		std::cerr << "glDeleteVertexArrays GL_INVALID_VALUE: _n is negative." << std::endl;
	} else {
		std::cerr << "Unknown glDeleteVertexArrays error." << std::endl;
	}
}

void checkGlDisableVertexAttribArray(GLenum err) {
	if (err == GL_INVALID_VALUE) {
		std::cerr << "glDisableVertexAttribArray  GL_INVALID_VALUE: _index is greater than or equal to ";
		std::cerr << "GL_MAX_VERTEX_ATTRIBS" << std::endl;
	} else {
		std::cerr << "Unknown glDisableVertexAttribArray error." << std::endl;
	}
}

void checkGlDrawArrays(GLenum err) {
	switch (err) {
		case GL_INVALID_ENUM:
			std::cerr << "glDrawArrays GL_INVALID_ENUM: _mode is not an accepted value." << std::endl;
			break;
		case GL_INVALID_VALUE:
			std::cerr << "glDrawArrays GL_INVALID_VALUE: _count is negative." << std::endl;
			break;
		case GL_INVALID_OPERATION:
			std::cerr << "glDrawArrays GL_INVALID_OPERATION: Either;";
			std::cerr << "\n\t1) A non-zero buffer object name is bound to an enabled array and the buffer object's ";
			std::cerr << "data store is currently mapped. Or,";
			std::cerr << "\n\t2) Recording the vertices of a primitive to the buffer objects being used for transform ";
			std::cerr << "feedback purposes would result in either exceeding the limits of any buffer object’s size, ";
			std::cerr << "or in exceeding the end position offset + size - 1, as set by glBindBufferRange.";
			std::cerr << std::endl;
			break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			std::cerr << "glDrawArrays GL_INVALID_FRAMEBUFFER_OPERATION: The currently bound framebuffer is not ";
			std::cerr << "framebuffer complete (i.e. the return value from glCheckFramebufferStatus is not ";
			std::cerr << "GL_FRAMEBUFFER_COMPLETE)." << std::endl;
			break;

		default:
			std::cerr << "Unknown glDrawArrays error." << std::endl;
			break;
	}
}

void checkGlDrawElements(GLenum err) {
	switch (err) {
		case GL_INVALID_ENUM:
			std::cerr << "glDrawElements GL_INVALID_ENUM: _mode is not an accepted value." << std::endl;
			break;
		case GL_INVALID_VALUE:
			std::cerr << "glDrawElements GL_INVALID_VALUE: _count is negative." << std::endl;
			break;
		case GL_INVALID_OPERATION:
			std::cerr << "glDrawElements GL_INVALID_OPERATION: Either;";
			std::cerr << "\n\t1) A non-zero buffer object name is bound to an enabled array or the element array and ";
			std::cerr << "the buffer object's data store is currently mapped. Or,";
			std::cerr << "\n\t2) Transform feedback is active and not paused." << std::endl;
			break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			std::cerr << "glDrawElements GL_INVALID_FRAMEBUFFER_OPERATION: The currently bound framebuffer is not ";
			std::cerr << "framebuffer complete (i.e. the return value from glCheckFramebufferStatus is not ";
			std::cerr << "GL_FRAMEBUFFER_COMPLETE)." << std::endl;
			break;

		default:
			std::cerr << "Unknown glDrawElements error." << std::endl;
	}
}

void checkGlEnableVertexAttribArray(GLenum err) {
	if (err == GL_INVALID_VALUE) {
		std::cerr << "glEnableVertexAttribArray  GL_INVALID_VALUE: _index is greater than or equal to ";
		std::cerr << "GL_MAX_VERTEX_ATTRIBS" << std::endl;
	} else {
		std::cerr << "Unknown glEnableVertexAttribArray error." << std::endl;
	}
}

void checkGlGenBuffers(GLenum err) {
	if (err == GL_INVALID_VALUE) {
		std::cerr << "glGenBuffers GL_INVALID_VALUE: _n is negative." << std::endl;
	} else {
		std::cerr << "Unknown glGenBuffers error." << std::endl;
	}
}

void checkGlGenVertexArrays(GLenum err) {
	if (err == GL_INVALID_VALUE) {
		std::cerr << "glGenVertexArrays GL_INVALID_VALUE: _n is negative." << std::endl;
	} else {
		std::cerr << "Unknown glGenVertexArrays error." << std::endl;
	}
}

void checkGlLinkProgram(GLenum err) {
	switch (err) {
		case GL_INVALID_VALUE:
			std::cerr << "glLinkProgram GL_INVALID_VALUE: _program is not a value generated by OpenGL." << std::endl;
			break;
		case GL_INVALID_OPERATION:
			std::cerr << "glLinkProgram GL_INVALID_OPERATION: Either;";
			std::cerr << "\n\t1) _program is not a program object.";
			std::cerr << "\n\t2) _program is the currently active program object and transform feedback mode is ";
			std::cerr << "active." << std::endl;
			break;

		default:
			std::cerr << "Unknown glLinkProgram error." << std::endl;
			break;
	}
}

void checkGlShaderSource(GLenum err) {
	switch (err) {
		case GL_INVALID_VALUE:
			std::cerr << "glShaderSource GL_INVALID_VALUE: Either;";
			std::cerr << "\n\t1) _shader is not a value generated by OpenGL. Or,";
			std::cerr << "\n\t2) _count is less than 0." << std::endl;
			break;
		case GL_INVALID_OPERATION:
			std::cerr << "glShaderSource GL_INVALID_OPERATION: _shader is not a shader object." << std::endl;
			break;

		default:
			std::cerr << "Unknown glShaderSource error." << std::endl;
			break;
	}
}

void checkGlTexImage2D(GLenum err) {
	switch (err) {
		case GL_INVALID_ENUM:
			std::cerr << "glTexImage2D GL_INVALID_ENUM: Either;";
			std::cerr << "\n\t1) _target is not GL_TEXTURE_2D, GL_TEXTURE_CUBE_MAP_POSITIVE_X, GL_TEXTURE_CUBE_MAP_NEGATIVE_X, GL_TEXTURE_CUBE_MAP_POSITIVE_Y, GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, GL_TEXTURE_CUBE_MAP_POSITIVE_Z, or GL_TEXTURE_CUBE_MAP_NEGATIVE_Z." << std::endl;
			std::cerr << "\n\t2) _type is not a type constant." << std::endl;
			std::cerr << "\n\t3) _internalFormat is not one of the accepted resolution and format symbolic constants." << std::endl;
			break;
		case GL_INVALID_VALUE:
			std::cerr << "glTexImage2D GL_INVALID_VALUE: Either;";
			std::cerr << "\n\t1) _target is one of the six cube map 2D image targets and the width and height parameters are not equal.";
			std::cerr << "\n\t2) _width is less than 0 or greater than GL_MAX_TEXTURE_SIZE.";
			std::cerr << "\n\t3) _level is less than 0.";
			std::cerr << "\n\t4) _level is greater than log_2(_max), where _max is the returned value of GL_MAX_TEXTURE_SIZE.";
			std::cerr << "\n\t5) _width or height is less than 0 or greater than GL_MAX_TEXTURE_SIZE.";
			std::cerr << "\n\t6) _border is not 0.";
			std::cerr << std::endl;
		case GL_INVALID_OPERATION:
			std::cerr << "glTexImage2D GL_INVALID_OPERATION: Either;";
			std::cerr << "\n\t1) The combination of _internalFormat, format and _type is not one of those in the tables above.";
			std::cerr << "\n\t2) A non-zero buffer object name is bound to the GL_PIXEL_UNPACK_BUFFER target and the buffer object's data store is currently mapped.";
			std::cerr << "\n\t3) A non-zero buffer object name is bound to the GL_PIXEL_UNPACK_BUFFER target and the data would be unpacked from the buffer object such that the memory reads required would exceed the data store size.";
			std::cerr << "\n\t4) A non-zero buffer object name is bound to the GL_PIXEL_UNPACK_BUFFER target and data is not evenly divisible into the number of bytes needed to store in memory a datum indicated by type.";
			std::cerr << std::endl;
			break;

		default:
			std::cerr << "Unknown glTexImage2D error." << std::endl;
			break;
	}
}

void checkGlTexParameteri(GLenum err) {
	if (err == GL_INVALID_ENUM) {
			std::cerr << "glTexParameteri GL_INVALID_ENUM: Either;";
			std::cerr << "\n\t1) _target or pname is not one of the accepted defined values.";
			std::cerr << "\n\t2) _params should have a defined constant value (based on the value of pname) and does not." << std::endl;
	} else {
		std::cerr << "Unknown glTexParameteri error." << std::endl;
	}
}

void checkGlUseProgram(GLenum err) {
	switch (err) {
		case GL_INVALID_VALUE:
			std::cerr << "glUseProgram GL_INVALID_VALUE: _program is neither 0 nor a value generated by OpenGL.";
			std::cerr << std::endl;
			break;
		case GL_INVALID_OPERATION:
			std::cerr << "glUseProgram GL_INVALID_OPERATION: Either;";
			std::cerr << "\n\t1) _program is not a program object. Or,";
			std::cerr << "\n\t2) _program could not be made part of current state. Or,";
			std::cerr << "\n\t3) _transform feedback mode is active and not paused." << std::endl;
			break;

		default:
			std::cerr << "Unknown glUseProgram error." << std::endl;
	}
}

void checkGlVertexAttribPointer(GLenum err) {
	switch (err) {
		case GL_INVALID_VALUE:
			std::cerr << "glVertexAttribPointer GL_INVALID_VALUE: Either;";
			std::cerr << "\n\t1) _index is greater than or equal to GL_MAX_VERTEX_ATTRIBS. Or,";
			std::cerr << "\n\t2) _size is not 1, 2, 3 or 4. Or,";
			std::cerr << "\n\t3) _stride is negative." << std::endl;
			break;

		case GL_INVALID_ENUM:
			std::cerr << "glVertexAttribPointer GL_INVALID_ENUM: _type is not an accepted value." << std::endl;
			break;

		case GL_INVALID_OPERATION:
			std::cerr << "glVertexAttribPointer GL_INVALID_OPERATION: Either;";
			std::cerr << "\n\t1) _type is GL_INT_2_10_10_10_REV or GL_UNSIGNED_INT_2_10_10_10_REV and size is not ";
			std::cerr << "4. Or,";
			std::cerr << "\n\t2) A non-zero vertex array object is bound, zero is bound to the GL_ARRAY_BUFFER ";
			std::cerr << "buffer object binding point and the pointer argument is not NULL." << std::endl;
			break;

		default:
			std::cerr << "Unknown glVertexAttribPointer error." << std::endl;
	}
}

void uinta::glCheckError(gl_error_check_type type) {
#ifdef UINTA_DEBUG
	GLenum err = glGetError();
	if (!err) return;

	switch (type) {
		case GL_ATTACH_SHADER:
			checkGlAttachShader(err);
			break;
		case GL_BIND_BUFFER:
			checkGlBindBuffer(err);
			break;
		case GL_BIND_TEXTURE:
			checkGlBindTexture(err);
			break;
		case GL_BIND_VERTEX_ARRAY:
			checkGlBindVertexArray(err);
			break;
		case GL_BUFFER_DATA:
			checkGlBufferData(err);
			return;
		case GL_BUFFER_SUB_DATA:
			checkGlBufferSubData(err);
			break;
		case GL_CLEAR:
			checkGlClear(err);
			break;
		case GL_COMPILE_SHADER:
			checkGlCompileShader(err);
			break;
		case GL_CREATE_PROGRAM:
			checkGlCreateProgram(err);
			break;
		case GL_CREATE_SHADER:
			checkGlCreateShader(err);
			break;
		case GL_DELETE_BUFFERS:
			checkGlDeleteBuffers(err);
			break;
		case GL_DELETE_SHADER:
			checkGlDeleteShader(err);
			break;
		case GL_DELETE_VERTEX_ARRAYS:
			checkGlDeleteVertexArrays(err);
			break;
		case GL_DISABLE_VERTEX_ATTRIB_ARRAY:
			checkGlDisableVertexAttribArray(err);
			break;
		case GL_DRAW_ARRAYS:
			checkGlDrawArrays(err);
			break;
		case GL_DRAW_ELEMENTS:
			checkGlDrawElements(err);
		case GL_ENABLE_VERTEX_ATTRIB_ARRAY:
			checkGlEnableVertexAttribArray(err);
			break;
		case GL_GEN_BUFFERS:
			checkGlGenBuffers(err);
			return;
		case GL_GEN_VERTEX_ARRAYS:
			checkGlGenVertexArrays(err);
			break;
		case GL_LINK_PROGRAM:
			checkGlLinkProgram(err);
			break;
		case GL_SHADER_SOURCE:
			checkGlShaderSource(err);
			break;
		case GL_TEX_IMAGE2D:
			checkGlTexImage2D(err);
			break;
		case GL_TEX_PARAMETERI:
			checkGlTexParameteri(err);
			break;
		case GL_USE_PROGRAM:
			checkGlUseProgram(err);
			break;
		case GL_VERTEX_ATTRIB_POINTER:
			checkGlVertexAttribPointer(err);
			return;
		default:
			std::cerr << "!!!   UNIMPLEMENTED glCheckError TYPE   !!!" << std::endl;
	}
#endif
}
