//
// Created by mfati on 12/20/2023.
//

#include "../../include/engine/Collider.h"

bool Collider::is_colliding_with(Collider other) const {
    auto pos = m_transform->get_position();
    auto size = m_transform->get_size();
    auto other_pos = other.get_transform()->get_position();
    auto other_size = other.get_transform()->get_size();
    int thisMinX = pos.x - size.x / 2;
    int thisMaxX = pos.x + size.x / 2;
    int thisMinY = pos.y - size.y / 2;
    int thisMaxY = pos.y + size.y / 2;

    int otherMinX = other_pos.x - other_size.x / 2;
    int otherMaxX = other_pos.x + other_size.x / 2;
    int otherMinY = other_pos.y - other_size.y / 2;
    int otherMaxY = other_pos.y + other_size.y / 2;

    if (thisMinX <= otherMaxX && thisMaxX >= otherMinX &&
        thisMinY <= otherMaxY && thisMaxY >= otherMinY) {
        return true;
    }

    return false;
}

void Collider::update() {
    m_transform = m_parent->get_transform();
}

void Collider::reset() {
    m_transform = m_parent->get_transform();

}
