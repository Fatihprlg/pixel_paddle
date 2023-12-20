//
// Created by mfati on 12/20/2023.
//

#ifndef PIXELPADDLE_COLLIDER_H
#define PIXELPADDLE_COLLIDER_H


#include "Vector2.h"
#include "Component.h"
#include "string"

class Collider : public Component{
private:
    Vector2 m_size;
    Vector2 m_position;
public:
    Collider(Vector2 size, Vector2 position);
    void set_size(Vector2 size);
    Vector2 get_size();
    void set_position(Vector2 position);
    Vector2 get_position();
    [[nodiscard]] bool is_colliding_with(Collider other) const;
};


#endif //PIXELPADDLE_COLLIDER_H
