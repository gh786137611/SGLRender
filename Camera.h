//
// Created by mm on 2019/11/20.
//

#ifndef SGLRENDER_CAMERA_H
#define SGLRENDER_CAMERA_H

#include "Common.h"

SGL_BEGIN

class Camera {
public:
    const glm::mat4 & projectionMatrix()const {
        return m_projectionMatrix;
    }

    virtual const glm::mat4 & viewMatrix()const {
        return m_viewMatrix;
    }

    static std::shared_ptr<PerspectiveCamera> createPerspective();

protected:
    Camera(){}
protected:
    glm::mat4 m_projectionMatrix;
    glm::mat4 m_viewMatrix;
};


class PerspectiveCamera: public Camera {
    friend Camera;
public:
    void lookat(const glm::vec3 & eye, const glm::vec3 & direction, const glm::vec3 & up) {
        m_position = eye;
        m_direction = direction;
        m_up = up;
        update_viewMatrix();
    }

    void perspective(float fov, float aspect, float near, float far) {
        m_fov = fov;
        m_aspsect = aspect;
        m_near = near;
        m_far = far;
        update_projectionMatrix();
    }

    const glm::vec3 & position()const {
        return m_position;
    }
    const glm::vec3 & direction()const {
        return m_direction;
    }
    const glm::vec3 & up()const {
        return m_up;
    }
    void set_position(const glm::vec3 & eye){
        m_position = eye;
        update_viewMatrix();
    }
    void set_direction(const glm::vec3 & direction){
        m_direction = direction;
        update_viewMatrix();
    }
    void set_up(const glm::vec3 & up){
        m_up = up;
        update_viewMatrix();
    }
private:
    PerspectiveCamera(){}
    void update_viewMatrix() {
        m_viewMatrix = glm::lookAt(m_position, m_position + m_direction, m_up);
    }

    void update_projectionMatrix() {
        m_projectionMatrix = glm::perspective(m_fov, m_aspsect, m_near, m_far);
    }

private:
    float m_fov;
    float m_aspsect;
    float m_near;
    float m_far;

    glm::vec3 m_position;
    glm::vec3 m_direction;
    glm::vec3 m_up;
};

SGL_END
#endif //SGLRENDER_CAMERA_H
