//
// Created by mfati on 12/22/2023.
//

#ifndef PIXELPADDLE_TRANSFORM_H
#define PIXELPADDLE_TRANSFORM_H


#include "Vector2.h"

class Transform {
private:
    Vector2 m_size;
    Vector2 m_position;
public:
    Transform();
    void set_size(Vector2 size);
    Vector2 get_size();
    void set_position(Vector2 pos);
    Vector2 get_position();
    Transform& operator=(const Transform& other);
};


#endif //PIXELPADDLE_TRANSFORM_H
