#include <cstdio>
#include <cstring> // for memcpy

#include <camera.hpp>
#include <glm/gtx/euler_angles.hpp>

void get_view_matrix(const camera2d& camera, mat4* mat) noexcept {
    *mat = mat4();
    mat->m00(WORLD_RIGHT.x);
    mat->m01(WORLD_RIGHT.y);
    mat->m02(WORLD_RIGHT.z);
    mat->m10(WORLD_UP.x);
    mat->m11(WORLD_UP.y);
    mat->m12(WORLD_UP.z);
    mat->m20(WORLD_FORWARD.x);
    mat->m21(WORLD_FORWARD.y);
    mat->m22(WORLD_FORWARD.z);
    mat->m30(camera.pos.x);
    mat->m31(camera.pos.y);

    // TODO get rid of glm and do our own 4x4 matrix inverse
    glm::mat4 gmat = glm::mat4(*mat->values);
    memcpy(&gmat[0][0], mat, sizeof(float) * 16);
    gmat = glm::inverse(gmat);
    memcpy(mat, &gmat[0][0], sizeof(float) * 16);
}

#include <glm/gtx/euler_angles.hpp>
void get_view_matrix(glm::mat4* mat, const glm::vec3& pos, const float pitch, const float yaw) noexcept {
    glm::mat4 transformx = glm::eulerAngleX(glm::radians(pitch));
    glm::mat4 transformy = glm::eulerAngleY(glm::radians(yaw));
    *mat = glm::translate(transformx * transformy, -pos);
}

void get_ortho_matrix(mat4 &mat, float left, float right, float bottom, float top, float near, float far) noexcept {
    glm::mat4 ortho = glm::ortho(left, right, bottom, top, near, far);
    memcpy(&mat, &ortho, sizeof(float) * 16);
}

