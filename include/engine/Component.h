//
// Created by mfati on 12/20/2023.
//

#ifndef PIXELPADDLE_COMPONENT_H
#define PIXELPADDLE_COMPONENT_H


#include <string>

class Component {
protected:
    int id;
    bool allow_multi_components;
public:
    Component();
    [[nodiscard]] bool is_allowing_multi_component() const;
    virtual void start();
    virtual void update();
    virtual void end();
};


#endif //PIXELPADDLE_COMPONENT_H
