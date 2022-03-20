#ifndef UINTA_WINDOW_H
#define UINTA_WINDOW_H

#include <GLFW/glfw3.h>

namespace window {
    extern unsigned int width;
    extern unsigned int height;
}

struct glfwdto {
    GLFWwindow* window = nullptr;
    const char *title = nullptr;
    unsigned int width = 0, height = 0;
};

void createGLFWWindow(glfwdto& dto);

#endif // UINTA_WINDOW_H
