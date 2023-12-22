//
// Created by mfati on 12/20/2023.
//

#ifndef PIXELPADDLE_GAMEMANAGER_H
#define PIXELPADDLE_GAMEMANAGER_H


#include <vector>
#include "GameObject.h"
#include "GameRenderer.h"
#include "InputManager.h"

class GameManager {
private:
    std::vector<GameObject*> m_game_objects;
    GameRenderer* m_game_renderer;
    InputManager* m_input_manager;
    bool m_is_quitting;
public:
    void setup_game();
    void update_frame();
    void game_loop();
    void shutdown();
    void add_game_object(GameObject* go);
    void remove_game_object(GameObject* go);
    void * quit_handler();
    GameRenderer* get_game_renderer();
    InputManager* get_input_manager();
};


#endif //PIXELPADDLE_GAMEMANAGER_H
