//
// Created by mfati on 12/20/2023.
//

#include "../../include/engine/GameObject.h"
#include "../../include/Constants.h"
#include <algorithm>
#include <iostream>

GameObject::GameObject(int id) : m_id(id), position(Vector2(0,0)), size(Vector2(1,1)), m_is_destroyed(false){}

GameObject::GameObject(int id, Vector2 position, Vector2 size) : m_id(id), position(position), size(size), m_is_destroyed(false){}

[[maybe_unused]] int GameObject::get_id() const {
    return m_id;
}

void GameObject::add_component(Component *comp) {
    auto it = find(m_components.begin(), m_components.end(),
                   comp);
    if (it != m_components.end() && !comp->is_allowing_multi_component()) {
        std::cout << "The component '" << NAMEOF(comp) << "' do not allow multi component.";
    }
    else{
        m_components.push_back(comp);
    }
}

void GameObject::remove_component(Component *comp) {
    auto it = find(m_components.begin(), m_components.end(),
                   comp);
    if (it != m_components.end()) {
        m_components.erase(it);
        comp->end();
        delete comp;
    }
}

void GameObject::start() {
    for (Component* comp: m_components) {
        comp->start();
    }
}

void GameObject::update() {
    for (Component* comp: m_components) {
        comp->update();
    }
}

void GameObject::end() {
    for (Component* comp: m_components) {
        comp->end();
        delete comp;
    }
}

template<class T>
T GameObject::get_component() {
    for(Component* comp: m_components){
        if(typeid(T) == typeid(comp)){
            return comp;
        }
    }
    return nullptr;
}

