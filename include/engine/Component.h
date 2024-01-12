//
// Created by mfati on 12/20/2023.
//

#ifndef PIXELPADDLE_COMPONENT_H
#define PIXELPADDLE_COMPONENT_H


#include <string>
#include "Transform.h"

class Component {
protected:
    int id;
    bool allow_multi_components;
    Component* m_parent;
    Transform* m_transform;
public:
    Component();
    [[nodiscard]] bool is_allowing_multi_component() const;
    void set_parent(Component* parent);
    Component* get_parent();
    Transform* get_transform();
    virtual void start();
    virtual void update();
    virtual void end();
    virtual void reset();
};


#endif //PIXELPADDLE_COMPONENT_H
