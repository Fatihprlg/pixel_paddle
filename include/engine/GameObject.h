//
// Created by mfati on 12/20/2023.
//

#ifndef PIXELPADDLE_GAMEOBJECT_H
#define PIXELPADDLE_GAMEOBJECT_H


#include <vector>
#include "Vector2.h"
#include "Component.h"

class GameObject : public Component{
private:
    int m_id;
    std::vector<Component*> m_components;
    bool m_is_destroyed;
public:
    Vector2 position;
    Vector2 size;
    explicit GameObject(int id);
    GameObject(int id, Vector2 position, Vector2 size);
    [[maybe_unused]] int get_id() const;
    void add_component(Component* comp);
    void remove_component(Component* comp);
    template<class T>
    T get_component();
    void start() override;
    void update() override;
    void end() override;

};

#endif //PIXELPADDLE_GAMEOBJECT_H
