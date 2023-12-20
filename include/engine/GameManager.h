//
// Created by mfati on 12/20/2023.
//

#ifndef PIXELPADDLE_GAMEMANAGER_H
#define PIXELPADDLE_GAMEMANAGER_H


#include <vector>
#include "GameObject.h"
#include "GameRenderer.h"

class GameManager {
private:
    std::vector<GameObject*> m_game_objects;
    GameRenderer* m_game_renderer;
public:
    void setup_game();
    void update_frame();
    void shutdown();
    void add_game_object(GameObject* go);
    void remove_game_object(GameObject* go);
    GameRenderer* get_game_renderer();

};


#endif //PIXELPADDLE_GAMEMANAGER_H
