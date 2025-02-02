#ifndef UINTA_BUFFER_HPP
#define UINTA_BUFFER_HPP

#include <GL/gl.h>

struct gl_buf {
    GLuint id;
    unsigned int count, max, offset;

    gl_buf() noexcept {
        id = 0;
        count = 0;
        max = 0;
        offset = 0;
    }

    gl_buf(const gl_buf& other) noexcept {
        *this = other;
    }

    gl_buf& operator=(const gl_buf& other) noexcept {
        id = other.id;
        count = other.count;
        max = other.max;
        offset = other.offset;
        return *this;
    }

};


#endif // UINTA_BUFFER_HPP
