#include<glad/glad.h>

#include <cmath>
#include <cstdio>
#include <cstring>

#include <file.hpp>
#include <font.hpp>
#include <shader.hpp>

#include "./fontrunner.hpp"

void fontRunner::init() {
    view.width = WINDOW_WIDTH;
    view.height = WINDOW_HEIGHT;
    view.title = "hello font";
    createGLFWWindow(view);

    init_font();
    init_shader();
    init_buffers();
    init_mesh();

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

void fontRunner::render() {
    glDrawElements(GL_TRIANGLES, icount, GL_UNSIGNED_INT, 0);
}

void fontRunner::tick(float dt) {
}

void fontRunner::init_buffers() {
    glGenVertexArrays(1, &vao);

    GLuint ids[2];
    glGenBuffers(2, ids);
    vbo = ids[0];
    ebo = ids[1];

    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*) (2 * sizeof(GLfloat)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(GLfloat), (void*) (4 * sizeof(GLfloat)));
    glEnableVertexAttribArray(2);
}

using namespace font;
void fontRunner::init_mesh() {
    const std::unordered_map<font_mesh_attrib_t, font_mesh_attrib> attribs = {
        {FontMeshAttrib_Position, font_mesh_attrib(7, 0)},
        {FontMeshAttrib_UV, font_mesh_attrib(7, 2)},
        {FontMeshAttrib_Color, font_mesh_attrib(7, 4)},
    };
    unsigned int vbuf_count = 0;
    unsigned int ioffset = 0;
    font::generate_mesh(&text, font_handle, view.width, view.height, attribs, vbuf, &vbuf_count, ibuf, &icount, &ioffset);

    glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * VBUF_SIZE, vbuf, GL_STATIC_DRAW);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * IBUF_SIZE, ibuf, GL_STATIC_DRAW);
}

void fontRunner::init_font() {
    auto type = font::DejaVuSans;
    font_handle = font::init_font(type, 256, 256);
    unsigned char data[getFontSize(type)];
    read_file_binary(getFontPath(type), (char*) data);
    load_font(font_handle, data);
}

void fontRunner::init_shader() {
    const char *vshader =
        "#version 330 core\n"
        "layout (location = 0) in vec2 in_pos;"
        "layout (location = 1) in vec2 in_uv;"
        "layout (location = 2) in vec3 in_color;"
        "out vec2 pass_uv;"
        "out vec3 pass_color;"
        "void main() {"
        "  pass_uv = in_uv;"
        "  pass_color = in_color;"
        "  gl_Position = vec4(in_pos, 0.0, 1.0);"
        "}\0";

    const char *fshader =
        "#version 330 core\n"
        "in vec2 pass_uv;"
        "in vec3 pass_color;"
        "uniform sampler2D atlas;"
        "out vec4 out_color;"
        "void main() {"
        "  out_color = vec4(pass_color, texture(atlas, pass_uv).r);"
        "}\0";

    const char* sources[] = { vshader, fshader };
    const GLenum stages[] = { GL_VERTEX_SHADER, GL_FRAGMENT_SHADER };
    shader = create_shader_program(sources, stages, sizeof(stages) / sizeof(GLenum));
    glUseProgram(shader);
}

void fontRunner::key_callback(int key, int scancode, int action, int mods) noexcept {
}
