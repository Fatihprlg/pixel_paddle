//
// Created by mfati on 12/22/2023.
//

#include "../../include/engine/Transform.h"

void Transform::set_size(Vector2 size) {
    m_size = size;
}

Vector2 Transform::get_size() {
    return m_size;
}

void Transform::set_position(Vector2 pos) {
    m_position = pos;
}

Vector2 Transform::get_position() {
    return m_position;
}

Transform &Transform::operator=(const Transform &other) {
    m_size = other.m_size;
    m_position = other.m_position;
    return *this;
}

Transform::Transform() {
    m_size = Vector2(0,0);
    m_position = Vector2(0,0);
}
