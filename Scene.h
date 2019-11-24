//
// Created by mm on 2019/11/22.
//

#ifndef SGLRENDER_SCENE_H
#define SGLRENDER_SCENE_H

#include "Common.h"
SGL_BEGIN
class Scene {
public:
    void draw(const Camera * camera);
    static std::shared_ptr<Scene> create();
    void add(std::shared_ptr<Object3D> obj){
        m_children.push_back(obj);
    }

private:
    void draw_obj(std::shared_ptr<Object3D> & obj, const Camera * camera, const glm::mat4 & mat);
private:
    std::list<std::shared_ptr<Object3D>> m_children;
};

SGL_END
#endif //SGLRENDER_SCENE_H
