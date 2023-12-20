//
// Created by mfati on 12/20/2023.
//

#include "../../include/engine/Collider.h"

Collider::Collider(Vector2 size, Vector2 position) : m_size(size), m_position(position) {}

void Collider::set_size(Vector2 size) {
    m_size = size;
}

void Collider::set_position(Vector2 position) {
    m_position = position;
}

Vector2 Collider::get_size() {
    return m_size;
}

Vector2 Collider::get_position() {
    return m_position;
}

bool Collider::is_colliding_with(Collider other) const {
    int thisMinX = m_position.x - m_size.x / 2;
    int thisMaxX = m_position.x + m_size.x / 2;
    int thisMinY = m_position.y - m_size.y / 2;
    int thisMaxY = m_position.y + m_size.y / 2;

    int otherMinX = other.get_position().x - other.get_size().x / 2;
    int otherMaxX = other.get_position().x + other.get_size().x / 2;
    int otherMinY = other.get_position().y - other.get_size().y / 2;
    int otherMaxY = other.get_position().y + other.get_size().y / 2;

    if (thisMinX <= otherMaxX && thisMaxX >= otherMinX &&
        thisMinY <= otherMaxY && thisMaxY >= otherMinY) {
        return true;
    }

    return false;
}
