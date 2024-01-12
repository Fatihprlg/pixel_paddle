//
// Created by mfati on 12/20/2023.
//

#ifndef PIXELPADDLE_COLLIDER_H
#define PIXELPADDLE_COLLIDER_H


#include "Vector2.h"
#include "Component.h"
#include "string"

class Collider : public Component{
public:
    void reset() override;
    void update() override;
    [[nodiscard]] bool is_colliding_with(Collider other) const;
};


#endif //PIXELPADDLE_COLLIDER_H
