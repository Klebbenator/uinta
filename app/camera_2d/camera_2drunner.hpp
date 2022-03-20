#ifndef UINTA_CAMERA_RUNNER_H
#define UINTA_CAMERA_RUNNER_H

#include <runner.h>
#include <camera2d.hpp>

#include <GL/gl.h>

const inline unsigned int BUF_SIZE = 2048;

struct camera2DRunner : public runner {
    camera2d camera;

    mat4 view_matrix;
    GLint u_view;

    mat4 proj_matrix;
    GLint u_proj;

    // vertex buffer
    float vbuf[BUF_SIZE];
    // count of verticies in buffer
    unsigned int vcount = 0u;

    // index buffer
    unsigned int ibuf[BUF_SIZE];
    // count of indices in buffer
    unsigned int icount = 0u;
    // offset for index
    unsigned int ioff = 0u;

    GLuint vao;
    GLuint vbo;
    GLuint ebo;
    GLuint shader;

    void init() override;

    void render() override; 

    void tick(float dt) override;

};

#endif // UINTA_CAMERA_RUNNER_H

