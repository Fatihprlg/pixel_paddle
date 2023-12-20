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

Component::Component() = default;
