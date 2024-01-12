//
// Created by mfati on 12/20/2023.
//

#include "../../include/engine/Component.h"

bool Component::is_allowing_multi_component() const {
    return allow_multi_components;
}

void Component::start() {

}

void Component::update() {

}

void Component::end() {

}

void Component::reset() {

}

Component *Component::get_parent() {
    return m_parent;
}

void Component::set_parent(Component *parent) {
    m_parent = parent;
}

Transform* Component::get_transform() {
    return m_transform;
}
Component::Component() = default;
